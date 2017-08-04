OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all : $(OBJS)
	$(CC) $(OBJS) -o doubly_linked_list

main.o : main.cpp doubly_linked_list.h
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o
