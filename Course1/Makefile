#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for build systems which support 2 platform: HOST and MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 	<FILE>.i - Builds <FILE>.i preprocessor output file
# 	<FILE>.asm - Builds <FILE>.asm assembly file
#	<FILE>.o - Builds <FILE>.o object file
#       compile-all - Compile all object files, but do not link
#       build - compile all object files and link into final executable
#       clean - remote all generated files
#
# Platform Overrides:
#	HOST- Host environment
#	MSP432 - Target embedded environment
#
#------------------------------------------------------------------------------
include sources.mk

OBJECTS=$(SOURCES:.c=.o)
DEPENDENCIES=$(SOURCES:.c=.d)

BASENAME = c1m2
TARGET = $(BASENAME).out

#General flags for both platforms
CFLAGS = -Wall -Werror -g -O0 -std=c99 -MD
CPPFLAGS = -E 
LDFLAGS = -Wl,-Map=$(BASENAME).map


#Platform Overrides
PLATFORM = HOST

ifeq ($(PLATFORM),HOST)

PLATFORM_TARGET = -DHOST
CC = gcc
SIZE = size

endif

ifeq ($(PLATFORM),MSP432)

PLATFORM_TARGET = -DMSP432
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SIZE = arm-none-eabi-size

LINKER_FILE = -T ../msp432p401r.lds

#Architecture Specific Flags
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
CFLAGS_ARCH = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs

endif

#Build rule
%.i:%.c
	$(CC) $(CPPFLAGS) $< $(CFLAGS) $(CFLAGS_ARCH) $(PLATFORM_TARGET) $(INCLUDES) -o $@

%.asm:%.c
	$(CC) -S $< $(CFLAGS) $(CFLAGS_ARCH) $(PLATFORM_TARGET) $(INCLUDES) -o $@

%.o:%.c
	$(CC) -c $< $(CFLAGS) $(CFLAGS_ARCH) $(PLATFORM_TARGET) $(INCLUDES) -o $@

$(TARGET):$(OBJECTS)
	        $(CC) $(OBJECTS) $(CFLAGS) $(CFLAGS_ARCH) $(LDFLAGS) $(LINKER_FILE) $(INCLUDES) -o $@
		$(SIZE) -Btd $(TARGET) $(OBJECTS)
		
.PHONY: compile-all
compile-all: $(OBJECTS) 

.PHONY: build
build: $(TARGET)

.PHONY: clean
clean:
	rm -f *.o *.d *.asm *.i  $(TARGET) $(BASENAME).map
