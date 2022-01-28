all: raylibProject

raylibProject: main.o window.o pipes.o Instance.o
	g++ -o raylibProject main.o window.o pipes.o Instance.o -lraylib 

Instance.o: Instance.cpp Instance.h
	g++ -c Instance.cpp

pipes.o: pipes.cpp pipes.h
	g++ -c pipes.cpp

window.o: window.cpp window.h
	g++ -c window.cpp

main.o: main.cpp
	g++ -c main.cpp
