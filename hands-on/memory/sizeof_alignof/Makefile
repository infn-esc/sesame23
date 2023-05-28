.PHONY: all clean

SRC := sizeof_alignof.cc
DEP := $(SRC:%=%.d)

CXX := g++
CXXFLAGS := -std=c++17 -O2 -g -Wall -MMD -march=native -mtune=native 
LDFLAGS := 

all: sizeof_alignof.m32 sizeof_alignof.m64 sizeof_alignof.mx32


clean:
	rm -f sizeof_alignof.m32 sizeof_alignof.m64 sizeof_alignof.mx32 $(DEP)

sizeof_alignof.m32: sizeof_alignof.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@ -m32

sizeof_alignof.mx32: sizeof_alignof.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@ -mx32

sizeof_alignof.m64: sizeof_alignof.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@ -m64

-include $(DEP)
