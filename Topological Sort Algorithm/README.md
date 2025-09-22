# Topological Sort Algorithm

Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering.

## Time Complexity

Best: O(V + E)
Average: O(V + E)
Worst: O(V + E)

Where V is the number of vertices and E is the number of edges.

## Space Complexity

O(V) for storing the graph and auxiliary data structures

## Example Use Case

Scheduling tasks with dependencies, course prerequisite ordering, build systems, and resolving symbol dependencies in linkers.
