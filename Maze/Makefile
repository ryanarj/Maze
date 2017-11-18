main: Maze.o bfsMazeEscape.o Position.o RescueRemy.o
	g++ Maze.o bfsMazeEscape.o Position.o RescueRemy.o -o main

RescueRemy.o: Maze.h bfsMazeEscape.h RescueRemy.cpp
	g++ -c RescueRemy.cpp

Maze.o: Maze.h Maze.cpp 
	g++ -c Maze.cpp

Position.o: Position.h Position.cpp
	g++ -c Position.cpp

bfsMazeEscape.o: bfsMazeEscape.h bfsMazeEscape.cpp
	g++ -c bfsMazeEscape.cpp

clean:
	rm *.o