OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all : $(OBJS)
	$(CC) $(OBJS) -o deque

main.o : main.cpp deque.h
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o
