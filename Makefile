# Compiles each cpp file individually as there is no cross dependence. -c flag is
# used to prevent linking issues with similarly named functions (namely main())
# 
# This version of make uses the files in every directory. This file only exists for travis. 
CC := g++ -std=c++14
CFLAGS := -Wall -g -c

SRCS := $(wildcard */*.cpp)

all:  
	$(CC) -c $(SRCS) 
clean:
	rm -rf *.o a.out* 
	
.PHONY: all clean