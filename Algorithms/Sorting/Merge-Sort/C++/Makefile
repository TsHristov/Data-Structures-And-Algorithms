OBJS = merge_sort.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all: $(OBJS)
	$(CC) $(OBJS) -o merge_sort
insertion_sort.o : merge_sort.cpp
	$(CC) $(CFLAGS) merge_sort.cpp

clean :
	\rm *.o		
