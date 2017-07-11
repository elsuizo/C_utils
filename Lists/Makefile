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


# # TODO(elsuizo:2017-07-11):hay que mejorar este Makefile, shared libraries no es muy comodo
test: tests_single_lists.out
	@./tests_single_lists.out

tests_single_lists.out:
	@echo Compiling $@
	@cc $(CFLAGS) src/lists_single_linked_list.c tests/vendor/unity.c tests/test_lists.c -o tests_single_lists.out
