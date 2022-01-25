all: raylibProject

raylibProject: main.o window.o
	g++ -o raylibProject main.o window.o -lraylib

window.o: window.cpp window.h
	g++ -c window.cpp

main.o: main.cpp
	g++ -c main.cpp
