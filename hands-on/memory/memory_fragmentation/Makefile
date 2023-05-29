.PHONY: all clean

SRC := heap-fragmentor.cc
DEP := $(SRC:%=%.d)

CXX := g++
CXXFLAGS := -std=c++17 -O2 -g -Wall -MMD -march=native -mtune=native
LDFLAGS :=

all: heap-fragmentor


clean:
	rm -f heap-fragmentor $(DEP)

heap-fragmentor: heap-fragmentor.cc Makefile
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@

-include $(DEP)
