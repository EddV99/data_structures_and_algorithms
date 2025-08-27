CC=gcc
INCLUDE_DIR=include
CFLAGS=-I$(INCLUDE_DIR) -g -Wall -Wextra
BUILD_DIR=build
CODE_DIRS=.
CFILES=$(foreach x, $(CODE_DIRS), $(wildcard $(x)/*.c))
# TODO: fix, only works for source code in . directory
OBJECTS=$(patsubst ./%.c,$(BUILD_DIR)/%.o,$(CFILES))

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

format:
	find -iname '*.h' -o -iname '*.c' | xargs clang-format -i

run: 
	./$(BUILD_DIR)/main

clean: 
	$(RM) $(BUILD_DIR)/*

.PHONY: all clean run format
