CC=clang
CFLAGS=-Wall -Wextra -Werror -pedantic-errors -std=c17 -g
TARGET=program.o
SRC=program.c

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: all
	./$(TARGET)