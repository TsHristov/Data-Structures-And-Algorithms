OBJS = counting_sort.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all: $(OBJS)
	$(CC) $(OBJS) -o counting_sort
insertion_sort.o : counting_sort.cpp
	$(CC) $(CFLAGS) counting_sort.cpp

clean :
	\rm *.o		
