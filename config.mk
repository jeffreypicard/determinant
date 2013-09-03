# program version
VERSION = 0.1
# program name
PROG_NAME = determinant

# Customize below to fit your needs.

# paths

# includes and libs
INCS =
LIBS = -lm

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\"
CFLAGS = -g -std=c99 -pedantic -Wall -O3 ${INCS} ${CPPFLAGS}
LDFLAGS = -s ${LIBS}

# compiler and linker
CC = gcc
LD = ${CC}
