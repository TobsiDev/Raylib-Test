all: raylibProject

raylibProject: main.o window.o entity.o pipe.o score.o
	g++ -o raylibProject main.o window.o entity.o pipe.o score.o -lraylib
#-s -static -lraylib -lopengl32 -lgdi32 -lwinmm

score.o: score.cpp score.h
	g++ -c score.cpp

pipe.o: pipe.cpp pipe.h
	g++ -c pipe.cpp

entity.o: entity.cpp entity.h
	g++ -c entity.cpp

window.o: window.cpp window.h 
	g++ -c window.cpp

main.o: main.cpp
	g++ -c main.cpp