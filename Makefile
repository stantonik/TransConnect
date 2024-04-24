APP:=TransConnect

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

FLAGS:=-Iinclude -std=c++11 -lncurses

ifeq ($(detected_OS), Windows)
	FLAGS+=-IC:\MinGW\include\ncurses
endif

SRCS:=src/*.cpp
SRCS+=include/gui/*.cpp

build:
	g++ $(SRCS) $(FLAGS) -o bin/$(APP)

run:
	./$(APP)
