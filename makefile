.PHONY: all clean

LIB+=-lgtest
CXX_FLAGS+=-std=c++11

all: main

main: *.cpp *.hpp
	g++ $^ -o $@ $(LIB)

clean:
	rm -rf main