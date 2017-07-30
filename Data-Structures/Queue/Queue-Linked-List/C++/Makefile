OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all : $(OBJS)
	$(CC) $(OBJS) -o queue

main.o : main.cpp queue.h
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o
