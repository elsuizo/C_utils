#-------------------------------------------------------------------------
#                      Makefile for testing libraries
#-------------------------------------------------------------------------
TARGET = out
cc     = clang

CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
FLAGS += -Werror

SRCDIR = src
INCDIR = inc
TESTDIR = tests

SOURCES       := $(wildcard $(SRCDIR)/*.c)
INCLUDES      := $(wildcard $(INCDIR)/*.h)

RM = rm -f


test: test_single_lists
	@./test.out


test_single_lists: $(SOURCES) $(INCLUDES)
	@echo "Compiling" "$@"
	@$(CC) $(CFLAGS) $? $(TESTDIR)/vendor/unity.c $(TESTDIR)/test_lists.c -o test.out

# auxiliar commands
.PHONY: clean
clean:
	rm -f *.o *.out

