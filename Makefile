
CFLAGS := -g -O0 -std=c17 -D_POSIX_C_SOURCE=200809L
SRCS := $(wildcard *.c)
EXES := $(patsubst %.c,%,$(SRCS))

all: $(EXES)
.PHONY: all

clean:
	rm -rf $(EXES)
.PHONY: clean
