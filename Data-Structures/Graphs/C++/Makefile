OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all : $(OBJS)
	$(CC) $(OBJS) -o graph

main.o : main.cpp graph.h
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o
