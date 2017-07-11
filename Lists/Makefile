CC = clang # C compiler
CFLAGS = -fPIC -Wall -Wextra -O2 -g # C flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
TARGET_LIB = liblists.so # target lib

# directories
SRCDIR   = src
INCDIR   = inc
OBJDIR   = obj
BINDIR   = bin


SOURCES       := $(wildcard $(SRCDIR)/*.c)
OBJS = $(SOURCES:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)

test: tests.out
	@./tests.out

tests.out:
	@echo Compiling $@
	@cc $(CFLAGS) -L/home/elsuizo/Repos/C_utils/Lists tests/vendor/unity.c tests/test_lists.c -o tests.out
