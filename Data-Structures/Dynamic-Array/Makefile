OBJS = main.o dynamic_array.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

all : $(OBJS)
	$(CC) $(OBJS) -o dynamic_array

main.o : main.cpp dynamic_array.h
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o
