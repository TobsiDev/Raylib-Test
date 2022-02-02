all: raylibProject

raylibProject: main.o window.o entity.o pipe.o
	g++ -o raylibProject main.o window.o entity.o pipe.o -lraylib
#-s -static -lraylib -lopengl32 -lgdi32 -lwinmm

pipe.o: pipe.cpp pipe.h
	g++ -c pipe.cpp

entity.o: entity.cpp entity.h
	g++ -c entity.cpp

window.o: window.cpp window.h 
	g++ -c window.cpp

main.o: main.cpp
	g++ -c main.cpp