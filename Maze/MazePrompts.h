#include <cassert>
#include <string>
// #include "Maze.h"

std::string WelcomePrompt("Welcome to the Rat in the Maze program, where we will find a\npath from the start cell to the end cell of a maze so that Remy\nmay escape.  You will first enter the data specifying the maze.\nAfter that, if escape is possible, we will show an escape path");

std::string StartPrompt("Enter the row and column indices of the start: ");
;
std::string ExitPrompt("Enter the row and column indices of the exit: ");

std::string OpenPositionsPrompt("For each row, enter the column indices of the open squares\nTerminate the row input with a non-positive value");
