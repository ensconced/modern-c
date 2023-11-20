CC=clang
CFLAGS=-Wall -Wextra -Wconversion -Wshorten-64-to-32 -Wconstant-conversion -Wliteral-range -Woverflow -Wimplicit-int -Werror -pedantic-errors -std=c17 -g

BIN_DIR=bin

$(BIN_DIR)/test: test.c lib.c ../test-utils/lib.c
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

test: $(BIN_DIR)/test
	$<
