BOOT_BASENAME   := bootloader

# e.g.
# OVL_221_BASENAME := 221
# OVL_226_BASENAME := 226

BUILD_DIR       := build
TOOLS_DIR       := tools


BOOT_DIR        := $(BOOT_BASENAME)

BOOT_ASM_DIR    := asm/$(BOOT_DIR)
BOOT_ASM_DIRS   := $(BOOT_ASM_DIR) $(BOOT_ASM_DIR)/data

BOOT_C_DIR      := src/$(BOOT_DIR)
BOOT_C_DIRS     := $(BOOT_C_DIR)

BOOT_ASSETS_DIR := assets/$(BOOT_DIR)
BOOT_BIN_DIRS   := $(BOOT_ASSETS_DIR)

BOOT_TARGET     := $(BUILD_DIR)/$(BOOT_BASENAME)

BOOT_S_FILES    := $(foreach dir,$(BOOT_ASM_DIRS),$(wildcard $(dir)/*.s))
BOOT_C_FILES    := $(foreach dir,$(BOOT_C_DIRS),$(wildcard $(dir)/*.c))
BOOT_BIN_FILES  := $(foreach dir,$(BOOT_BIN_DIRS),$(wildcard $(dir)/*.bin))

BOOT_O_FILES    := $(foreach file,$(BOOT_S_FILES),$(BUILD_DIR)/$(file).o) \
                   $(foreach file,$(BOOT_C_FILES),$(BUILD_DIR)/$(file).o) \
                   $(foreach file,$(BOOT_BIN_FILES),$(BUILD_DIR)/$(file).o)

# TOOLS

MAKE            := make
PYTHON          := python3
WINE            := wine
SED             := sed
UNIX2DOS        := unix2dos

CPP             := cpp -P

CROSS           := mips-elf-
AS              := $(CROSS)as -EL
LD              := $(CROSS)ld -EL
OBJCOPY         := $(CROSS)objcopy

CC_PSYQ_40      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.0/CC1PSX.EXE -quiet
CC_PSYQ_41      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.1/CC1PSX.EXE -quiet
CC_PSYQ_43      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.3/CC1PSX.EXE -quiet
CC_PSYQ_46      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.6/CC1PSX.EXE -quiet

AS_PSYQ_40      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.0/ASPSX.EXE -quiet
AS_PSYQ_41      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.1/ASPSX.EXE -quiet
AS_PSYQ_43      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.3/ASPSX.EXE -quiet
AS_PSYQ_46      := $(WINE) $(TOOLS_DIR)/psyq/psyq4.6/ASPSX.EXE -quiet


PSYQ2ELF        := $(TOOLS_DIR)/psyq/psyq-obj-parser

CC              := $(CC_PSYQ_46)

SPLAT           := $(PYTHON) $(TOOLS_DIR)/splat/split.py


# FLAGS

AS_FLAGS        := -Iinclude -march=r3000 -mtune=r3000

CPP_INCLUDES    := -Iinclude -Iinclude/psyq
CPP_FLAGS       := -undef -Wall -lang-c
CPP_FLAGS       += -Dmips -D__GNUC__=2 -D__OPTIMIZE__ -D__mips__ -D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D__EXTENSIONS__ -D_MIPSEL -D__CHAR_UNSIGNED__ -D_LANGUAGE_C -DLANGUAGE_C
CPP_FLAGS       += $(CPP_INCLUDES)

ifdef PERMUTER
CPP_FLAGS       += -DPERMUTER
endif

CC_FLAGS        := -G0 -Wall -fno-builtin
OPT_FLAGS       := -O2

BOOT_LD_FLAGS   := -Map $(BOOT_TARGET).map -T $(BOOT_BASENAME).ld \
                   -T undefined_syms_auto.$(BOOT_BASENAME).txt -T undefined_funcs_auto.$(BOOT_BASENAME).txt -T undefined_syms.$(BOOT_BASENAME).txt \
				   --no-check-sections

OBJCOPY_FLAGS   := -O binary

# OVERRIDES


$(BUILD_DIR)/src/bootloader/1DAB0.c.o: CC := $(CC_PSYQ_46)

$(BUILD_DIR)/src/bootloader/1E4AC.c.o: CC := $(CC_PSYQ_46)
# $(BUILD_DIR)/src/bootloader/1E4AC.c.o: AS := $(AS_PSYQ_46)
# $(BUILD_DIR)/src/bootloader/1E4AC.c.o: AS_FLAGS :=
# $(BUILD_DIR)/src/bootloader/1E4AC.c.o: CPP_FLAGS += -DINCLUDE_ASM

$(BUILD_DIR)/src/bootloader/67070.c.o: CC := $(CC_PSYQ_40)

# psyq + objconverter
$(BUILD_DIR)/src/bootloader/67000.c.o: CC := $(CC_PSYQ_40)
$(BUILD_DIR)/src/bootloader/67000.c.o: AS := $(AS_PSYQ_40)
$(BUILD_DIR)/src/bootloader/67000.c.o: AS_FLAGS :=
$(BUILD_DIR)/src/bootloader/67000.c.o: CPP_FLAGS += -DINCLUDE_ASM

default: all

all: dirs verify

dirs:
	$(foreach dir,$(BOOT_ASM_DIRS) $(BOOT_BIN_DIRS) $(BOOT_C_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))


check: $(BOOT_BASENAME).ok
verify: $(BOOT_TARGET).ok

extract: $(BOOT_BASENAME).yaml
	$(SPLAT) $<

clean:
	rm -rf $(BUILD_DIR)

very-clean: clean
	rm -rf $(BOOT_ASM_DIR) $(BOOT_ASSETS_DIR)
	rm -rf *auto*.txt
	rm -rf *.ld


$(BOOT_TARGET).dat: $(BOOT_TARGET).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

$(BOOT_TARGET).elf: $(BOOT_O_FILES)
	$(LD) $(BOOT_LD_FLAGS) -o $@

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/%.c.o: %.c
	$(CPP) $(CPP_FLAGS) $(CPP_TARGET) $< | $(UNIX2DOS) | $(CC) $(CC_FLAGS) $(OPT_FLAGS) -o $@.s
	$(AS) $(AS_FLAGS) $@.s -o $@.obj
	if [[ "$$(dd if=$@.obj bs=1 skip=1 count=3 status=none)" = "ELF" ]] ; then cp $@.obj $@; else $(PSYQ2ELF) $@.obj -o $@ ; fi

%.ok: %.dat
	@echo "$$(cat $(notdir $(<:.dat=)).sha1)  $<" | sha1sum --check
	@touch $@

# keep .obj files
.SECONDARY:

.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
