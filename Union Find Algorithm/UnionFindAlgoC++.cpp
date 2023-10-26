// C++ implementation of disjoint set
#include <iostream>
using namespace std;
class DisjointSet {
int *rank, *parent, n;

public:
// Constructor to create and
// initialize sets of n items
DisjointSet(int n)
{
rank = new int[n];
parent = new int[n];
this->n = n;
make_set();
}

// Creates n single item sets
void make_set()
{
for (int i = 0; i < n; i++) {
parent[i] = i;
}
}

// Finds set of given item x
int find_set(int x)
{
// Finds the representative of the set
// that x is an element of
if (parent[x] != x) {

// if x is not the parent of itself
// Then x is not the representative of
// his set,
parent[x] = find_set(parent[x]);

// so we recursively call Find on its parent
// and move i's node directly under the
// representative of this set
}

return parent[x];
}

// Do union of two sets represented
// by x and y.
void Union(int x, int y)
{
// Find current sets of x and y
int xset = find_set(x);
int yset = find_set(y);

// If they are already in same set
if (xset == yset)
return;

// Put smaller ranked item under
// bigger ranked item if ranks are
// different
if (rank[xset] < rank[yset]) {
parent[xset] = yset;
}
else if (rank[xset] > rank[yset]) {
parent[yset] = xset;
}

// If ranks are same, then increment
// rank.
else {
parent[yset] = xset;
rank[xset] = rank[xset] + 1;
}
}
};

int main()
{
DisjointSet obj(5);
obj.Union(0, 2);
obj.Union(4, 2);
obj.Union(3, 1);
if (obj.find_set(4) == obj.find_set(0))
cout << "Yes\n";
else
cout << "No\n";
if (obj.find_set(1) == obj.find_set(0))
cout << "Yes\n";
else
cout << "No\n";

return 0;
}