#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Item
{
	struct Item* next;
	struct Item* prev;
};

struct LinkedList
{
	struct Item* first;
	struct Item* last;
	int count;
};

void LinkedList_Clear(struct LinkedList* L);
void LinkedList_AddFront(struct LinkedList* L, struct Item* I);
void LinkedList_AddBack(struct LinkedList* L, struct Item* I);

void* LinkedList_GetNextItem(struct Item* I);
void* LinkedList_GetFirstItem(struct LinkedList* L);

struct Item* LinkedList_RemoveMember(struct LinkedList* L, struct Item* I);
struct Item* LinkedList_RemoveFront(struct LinkedList* L);
struct Item* LinkedList_RemoveBack(struct LinkedList* L);

void LinkedList_Init(struct LinkedList* L, struct Item* item, int itemSize, int numItems);

#endif
