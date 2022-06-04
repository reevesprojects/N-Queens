#Benjamin Reeves
#CS 262, Lab section 208
#Project 1
CC = gcc
CFLAGS= -g -Wall -std=c89 -pedantic-errors -O
TARGET = p1_breeves6_208

all: $(TARGET).c
	$(CC) $(TARGET).c -o $(TARGET) $(CFLAGS)
clean:
	rm $(TARGET)