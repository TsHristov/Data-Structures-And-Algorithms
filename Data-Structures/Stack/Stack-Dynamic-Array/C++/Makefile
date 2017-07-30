OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all : $(OBJS)
	$(CC) $(OBJS) -o stack

main.o : main.cpp stack.h
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o
