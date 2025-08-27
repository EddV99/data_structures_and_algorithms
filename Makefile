CC=gcc
INC_DIR=include
CFLAGS=-I$(INC_DIR) -g -Wall -Wextra
BUILD_DIR=build
CODE_DIRS=.
CFILES=$(foreach x, $(CODE_DIRS), $(wildcard $(x)/*.c))
OBJECTS=$(patsubst ./%.c,$(BUILD_DIR)/%.o,$(CFILES))

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

format:
	find -iname '*.h' -o -iname '*.c' | xargs clang-format -i

run: 
	./$(BUILD_DIR)/main

clean: 
	rm build/*

.PHONY: all clean run format
