CC := gcc

APP += test_str 
APP += test_ch

SRCS += ch.c
SRCS += str.c
INCS += .

CFLAGS += -Wall
CFLAGS += -Wformat=0
ifdef DEBUG
CFLAGS += -g
endif

default: $(APP)

$(APP): $(SRCS:%.c=obj/%.o)
	@mkdir -p bin
	$(CC) -o bin/$@ test/$@.c $? $(INCS:%=-I%) $(CFLAGS)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(INCS:%=-I%) $(CFLAGS)

clean:
	rm -f $(SRCS:%.c=obj/%.o)
	rm -f $(APP:%=bin/%)

