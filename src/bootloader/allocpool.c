#include "common.h"
#include "linkedlist.h"

// complete struct
struct AllocPool
{
    struct LinkedList free;
    struct LinkedList taken;

    int maxItems;
    unsigned int itemSize;
    int poolSize;
    void* ptrPoolData;
};

void AllocPool_Clear(struct AllocPool* AP)
{
  unsigned int loopIndex;
  unsigned int currSlot;

  currSlot = (int)AP->ptrPoolData;

  loopIndex = 0;

  // clear list of free and taken
  LinkedList_Clear(&AP->free);
  LinkedList_Clear(&AP->taken);

  if (AP->maxItems != 0)
  {
    do
	{
	  // add all pool items to the free list
      LinkedList_AddFront(&AP->free,(struct Item*)currSlot);

	  loopIndex = loopIndex + 1;

	  // same as & 0xfffffffc, but more optimal
      currSlot += ((AP->itemSize)>>2)<<2;

    } while (loopIndex < AP->maxItems);
  }
}

void AllocPool_Init(struct AllocPool* AP,int maxItems,int itemSize,char* name)
{
  memset(AP,0,sizeof(struct AllocPool));

  AP->maxItems = maxItems;
  AP->itemSize = itemSize;
  AP->poolSize = maxItems * itemSize;

  // all items in a pool
  AP->ptrPoolData =
	MEMPACK_AllocMem(AP->poolSize,name);

  AllocPool_Clear(AP);

  return;
}

int AllocPool_Add(struct AllocPool* AP)
{
  struct Item* item;
  item = AP->free.first;

  if(AP->free.first != 0)
  {
	LinkedList_RemoveMember(&AP->free,item);
	LinkedList_AddFront(&AP->taken,item);
	return (int)item;
  }

  return 0;
}

void AllocPool_Remove(struct AllocPool* AP, struct Item* item)
{
  LinkedList_RemoveMember(&AP->taken,item);
  LinkedList_AddFront(&AP->free,item);
}
