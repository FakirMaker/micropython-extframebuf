# Location of top-level MicroPython directory
MPY_DIR = ../../..

# Name of module (different to built-in framebuf so it can coexist)
MOD = extframebuf

# Source files (.c or .py)
SRC = extframebuf.c

# Architecture to build for (x86, x64, armv7m, xtensa, xtensawin)
ARCH = xtensawin

include $(MPY_DIR)/py/dynruntime.mk
