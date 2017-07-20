CC=g++

CFLAGS=-g -c -Wall

all: dynamic_array

dynamic_array: main.o dynamic_array.o
							 $(CC) main.o dynamic_array.o -o dynamic_array
							 
main.o: main.cpp
				$(CC) $(CFLAGS) main.cpp

dynamic_array.o: dynamic_array.cpp
								$(CC) $(CFLAGS) dynamic_array.cpp
