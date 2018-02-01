OBJS = insertion_sort.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all: $(OBJS)
	$(CC) $(OBJS) -o insertion_sort
insertion_sort.o : insertion_sort.cpp
	$(CC) $(CFLAGS) insertion_sort.cpp

clean :
	\rm *.o		
