#include <vector>
#include "Position.h"
#ifndef _POSTABLE
#define  _POSTABLE

template <class T>
void init_table(vector<vector<T> > &t, int size, T defaultVal)
{
    t.resize(size);
    for(int i = 0; i < size; ++i)
        t[i].resize(size,defaultVal);
}

template <class T>
T getEntry(const vector<vector<T> > &t, Position P)
{
  return t[P.row][P.col];
}

template <class T>
void setEntry(vector<vector<T> > &t, Position P, T val)
{
  t[P.row][P.col] = val;
}

#endif

