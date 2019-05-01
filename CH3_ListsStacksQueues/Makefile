# Compiles each cpp file individually as there is no cross dependence. -c flag is
# used to prevent linking issues with similarly named functions (namely main())
CC := g++ -std=c++14
CFLAGS := -Wall -g -c

SRCS := $(wildcard *.cpp)

all:  
	$(CC) -c $(SRCS) 
clean:
	rm -rf *.o a.out* 
	
.PHONY: all clean