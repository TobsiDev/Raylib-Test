all: raylibProject

raylibProject: main.o window.o entity.o
	g++ -o raylibProject main.o window.o entity.o -lraylib
#-s -static -lraylib -lopengl32 -lgdi32 -lwinmm

entity.o: entity.cpp entity.h
	g++ -c entity.cpp

window.o: window.cpp window.h 
	g++ -c window.cpp

main.o: main.cpp
	g++ -c main.cpp