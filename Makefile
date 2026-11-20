CC = gcc
CFLAGS = -std=c99

SOURCES = main.c dataset.c sorting.c searching.c naive.c rabin_karp.c lcs.c maximumsubarray.c activity_selection.c huffman.c

TARGET = newsroom

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)