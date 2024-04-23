
FLAGS:=-Iinclude -std=c++11 -lncurses

SRCS:=src/*.cpp
SRCS+=include/gui/*.cpp

run:
	g++ $(SRCS) $(FLAGS) -o bin/TransConnect
