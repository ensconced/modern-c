CC=clang
CFLAGS=-Wall -std=c17
TARGET=program.o
SRC=program.c

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: all
	./$(TARGET)