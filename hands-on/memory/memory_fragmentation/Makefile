SRC=$(wildcard *.cc)
OBJ=$(SRC:%=%.o)
DEP=$(SRC:%=%.d)

CXX=g++
CXXFLAGS=-std=c++17 -O2 -g -Wall -MMD -march=native -mtune=native 

LD=g++
LDFLAGS=

.PHONY: all clean

all: heap-fragmentor


clean:
	rm -f heap-fragmentor $(OBJ) $(DEP)

heap-fragmentor: heap-fragmentor.cc Makefile
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@

-include $(DEP)
