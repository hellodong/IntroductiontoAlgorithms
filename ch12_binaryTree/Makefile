

CC=gcc
BIN=tree
BUILD_DIR=./build

CFLAGS=-std=gnu99 -g
LDFLAGS=
OBJS 	:=$(BUILD_DIR)/tree.o
OBJS 	+=$(BUILD_DIR)/main.o

all:$(BUILD_DIR) $(BIN)

$(BUILD_DIR):
	mkdir $@

$(BIN):$(OBJS)
	$(CC) $^ -o $@

$(BUILD_DIR)/%.o:%.c
	$(CC) $< $(CFLAGS) -c -o $@

.PHONY:
	clean clean_all

clean:
	rm $(OBJS) $(BIN) -rf
clean_all:
	rm $(BUILD_DIR) $(BIN) -rf
