CC := gcc

SRCS += test/main.c
SRCS += string.c
INCS += .

CFLAGS += -Wall
ifdef DEBUG
CFLAGS += -g
endif

default: $(SRCS:%.c=obj/%.o)
	@mkdir -p bin
	$(CC) -o bin/test $? $(INCS:%=-I%) $(CFLAGS)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(INCS:%=-I%) $(CFLAGS)

clean:
	rm -f $(SRCS:%.c=obj/%.o)
	rm -f bin/test

