CC=clang
CFLAGS=-Wall -Wextra -Werror -pedantic-errors -std=c17 -g
BIN_DIR=bin

.PHONY: run clean

$(BIN_DIR)/main: main.c
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

run: $(BIN_DIR)/main
	$<
