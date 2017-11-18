#ifndef DFS_C
#define DFS_C
#include "Position.h"
#include "table.h"
#include <stack>

typedef enum{OPEN,WALL,VISITED} state;

class Maze
{
  public:
   // The only constructor is one that inputs data from cin
   Maze(bool verbose); // verbose = true: print prompt                     
   void visit(Position P);
   void display() const;
   bool isValidPosition(Position P);
   bool isOpen(Position P);
   Position getOpenNeighbor(Position P);
   friend void dfsFindExit(Maze &M);
   friend void bfsFindExit(Maze &maze);
  private:
   int size;
   Position start;
   Position exitpos;

   vector<vector<state> > grid;
};

void printPath(stack<Position> &path);
void printPath(vector<vector<Position> > &predecessor, Position target);

#endif
