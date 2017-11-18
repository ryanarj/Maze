#include <cassert>
#include "MazePrompts.h"
#include "Maze.h"
#include "table.h"

using namespace std;

Maze::Maze(bool verbose)
// verbose == true means an intro and prompts for input will be output
{
  int i, j, dimension;
  
  if (verbose) {
    cout << WelcomePrompt << endl;
  }   
  cin >> dimension;
  size = dimension+2; // add the hedge rows and columns
  if (verbose)
    cout << StartPrompt << endl;
  cin >> start;
  if (verbose)
    cout << ExitPrompt << endl;
  cin >> exitpos;

  init_table(grid,size,WALL); 

  if(verbose) {
    cout << OpenPositionsPrompt << endl;
  }
  for (i = 1; i <= size-2; i++) {
    if (verbose)
      cout << "Row " << i << ": ";  
    cin >> j;
    assert(j < 1 || 1 <= j && j <= size-2);
    
    while (j > 0){
      grid[i][j] = OPEN;
      cin >> j;
      assert(j < 1 || 1 <= j && j <= size-2);
    };
  }
  
  if (!(grid[start.row][start.col] == OPEN)) 
    grid[start.row][start.col] = OPEN;
}

bool Maze::isValidPosition(Position P)
{
  return (0 < P.row && P.row < size-1) && (0 < P.col && P.col < size-1);
}

bool Maze::isOpen(Position P)
{
  return getEntry(grid,P) == OPEN;
}

void Maze::visit(Position P)
{
  assert(isValidPosition(P));
  setEntry(grid,P,VISITED);
}

Position Maze::getOpenNeighbor(Position P)
{
  Position nbr;
  direction d = DOWN;
  while(d != NONE) {
    nbr = P.Neighbor(d);
    if (isOpen(nbr))
      return nbr;
    d = next_direction(d);
  }
  return NULLPOS; // No open neighbor
}



void Maze::display() const
{
  cout << '\n';
  cout << "Your maze:\n" << endl;
  for (int i=0; i < size;i++) {
    for (int j=0; j < size; j++) {
      if (Position(i,j) == start && start == exitpos)
	cout << " b "; // for both
      else if (Position(i,j) == start)
	cout << " s ";
      else if (Position(i,j) == exitpos)
	cout << " e ";
      else if (grid[i][j] == WALL)
	cout << " * ";
      else
	cout << " - ";
    }
    cout << '\n';
  }
  cout << '\n';
}


void printPath(stack<Position> & path)
{
  stack<Position> tmp;
  while(!path.empty()) {
    tmp.push(path.top());
    path.pop();
  }
  while(!tmp.empty()) {
    cout << tmp.top() << " ";
    tmp.pop();
  }
  cout << endl;
  return;
}

void printPath(vector<vector<Position> > &predecessor, const Position target)
{
  if(target == NULLPOS)
    return;
  printPath(predecessor,getEntry(predecessor,target));
  cout << target << " ";
}
