all: raylibProject

raylibProject: main.o window.o pipes.o
	g++ -o raylibProject main.o window.o pipes.o -lraylib 

pipes.o: pipes.cpp pipes.h
	g++ -c pipes.cpp

window.o: window.cpp window.h
	g++ -c window.cpp

main.o: main.cpp
	g++ -c main.cpp
