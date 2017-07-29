#
# Pavel Kirienko, 2014 <pavel.kirienko@gmail.com>
#

CPPSRC := $(wildcard src/*.cpp)                  \
          $(wildcard src/sys/*.cpp)

CSRC   := $(wildcard src/*.c)

DEF = -D __SAMV71Q21__

INC = -Isrc/sys                         \
      -isystem libchip/include          \
      -isystem libchip/include/cmsis/CMSIS/Include

#
# Build configuration
#

BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj
DEPDIR = $(BUILDDIR)/dep

DEF += -DCORE_M7 -DTHUMB_NO_INTERWORKING -U__STRICT_ANSI__

FLAGS = -mthumb -mcpu=cortex-m7 -mno-thumb-interwork -O1 -g3 -Wall -Wextra -Wundef -ffunction-sections \
        -fdata-sections -fno-common -fno-exceptions -fno-unwind-tables -fno-stack-protector -fomit-frame-pointer \
        -Wfloat-equal -Wconversion -Wsign-conversion -Wmissing-declarations

C_CPP_FLAGS = $(FLAGS) -MD -MP -MF $(DEPDIR)/$(@F).d

CFLAGS = $(C_CPP_FLAGS) -std=c99

CPPFLAGS = $(C_CPP_FLAGS) -pedantic -std=c++14 -fno-rtti -fno-threadsafe-statics

LDFLAGS = $(FLAGS) -nodefaultlibs -lc -lgcc -nostartfiles -Tp.ld -Xlinker --gc-sections \
          -Wl,-Map,$(BUILDDIR)/output.map

# Link with nano newlib. Other toolchains may not support this option, so it can be safely removed.
LDFLAGS += --specs=nano.specs

COBJ   = $(addprefix $(OBJDIR)/, $(notdir $(CSRC:.c=.o)))
CPPOBJ = $(addprefix $(OBJDIR)/, $(notdir $(CPPSRC:.cpp=.o)))
OBJ = $(COBJ) $(CPPOBJ)

VPATH = $(sort $(dir $(CSRC)) $(dir $(CPPSRC)))

ELF = $(BUILDDIR)/firmware.elf
BIN = $(BUILDDIR)/firmware.bin

#
# Rules
#

TOOLCHAIN ?= arm-none-eabi-
CC   = $(TOOLCHAIN)gcc
CPPC = $(TOOLCHAIN)g++
AS   = $(TOOLCHAIN)gcc
LD   = $(TOOLCHAIN)g++
CP   = $(TOOLCHAIN)objcopy
SIZE = $(TOOLCHAIN)size

all: $(OBJ) $(ELF) $(BIN) size

$(OBJ): | $(BUILDDIR)

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(DEPDIR)
	@mkdir -p $(OBJDIR)

$(BIN): $(ELF)
	@echo
	$(CP) -O binary $(ELF) $@

$(ELF): $(OBJ)
	@echo
	$(LD) $(OBJ) $(LDFLAGS) -o $@

$(COBJ): $(OBJDIR)/%.o: %.c
	@echo
	$(CC) -c $(DEF) $(INC) $(CFLAGS) $< -o $@

$(CPPOBJ): $(OBJDIR)/%.o: %.cpp
	@echo
	$(CPPC) -c $(DEF) $(INC) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)

size: $(ELF)
	@if [ -f $(ELF) ]; then echo; $(SIZE) $(ELF); echo; fi;

.PHONY: all clean size $(BUILDDIR)

# Include the dependency files, should be the last of the makefile
-include $(shell mkdir $(DEPDIR) 2>/dev/null) $(wildcard $(DEPDIR)/*)

