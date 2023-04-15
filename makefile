.PHONY: all clean

LIB+=-lgtest

all: main

main: *.cpp *.hpp
	g++ $^ -o $@ $(LIB)

clean:
	rm -rf main