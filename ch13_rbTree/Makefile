

BUILD_DIR=build
SRC_DIR=source
OBJS	:=$(BUILD_DIR)/rbTreex.o
OBJS	+=$(BUILD_DIR)/main.o

CC=gcc
CFLAGS	:= -g -Wall
LDFLAGS :=
BIN		:= rbTreeDemo

all:$(BUILD_DIR) $(BIN)

$(BUILD_DIR):
	@mkdir $@
$(BIN):$(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)
$(BUILD_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $< $(CFLAGS) -c -o $@

.PHONY:clean distclean

clean:
	rm $(OBJS) $(BIN) -rf

distclean:
	rm $(BUILD_DIR) $(BIN) -rf


