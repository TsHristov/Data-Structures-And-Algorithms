OBJS = heap_sort.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all: $(OBJS)
	$(CC) $(OBJS) -o heap_sort

insertion_sort.o : heap_sort.cpp
	$(CC) $(CFLAGS) heap_sort.cpp

clean :
	\rm *.o		
