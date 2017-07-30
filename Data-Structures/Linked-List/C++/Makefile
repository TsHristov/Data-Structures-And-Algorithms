OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all : $(OBJS)
	$(CC) $(OBJS) -o linked_list

main.o : main.cpp linked_list.h
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o
