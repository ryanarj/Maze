// Author: Karshan Arjun

#include <stack>
#include <queue>
#include "bfsMazeEscape.h"
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

void bfsFindExit(Maze &M)
{
    queue<Position> Q;
    direction d;
    vector<vector<Position> > pred;
    init_table(pred,M.size,NULLPOS);
    Position current, nbr;
    
    // Make current first
    current = M.start;
    M.visit(current);
    Q.push(current);
    
    // Pop the queue until it is full
    while(!Q.empty()){
        current = Q.front();
        Q.pop();
        if(current == M.exitpos){
            cout << "Path to exit:\n\n";
            printPath(pred, M.exitpos);
            break;
        }
        d=DOWN;
        
        // Get the next direction
        while (d != NONE) {
            nbr = current.Neighbor(d);
            if(M.isOpen(nbr)){
                Q.push(nbr);
                M.visit(nbr);
                setEntry(pred, nbr, current);
            }
            d = next_direction(d);
        }
        
    }
}



