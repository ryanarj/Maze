#include <iostream>
#include "Maze.h"
#include "bfsMazeEscape.h" 

using namespace std;

int main(int argc, char **argv)
{
  bool prompt;
  
  if(argc > 1)
    prompt = true;
  else
    prompt = false;
  
  Maze RatHaus(prompt);

  RatHaus.display();
  bfsFindExit(RatHaus);
  cout << "\n\n";

  return 0;
}

