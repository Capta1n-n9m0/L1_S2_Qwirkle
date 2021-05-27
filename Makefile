CC=gcc
CFLAGS=-Wall

SOURCES=$(wildcard *.c )
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=qwirkle


%.o: %.c
	$(CC) -c -o $@ $^


$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^