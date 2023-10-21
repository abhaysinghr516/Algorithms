# TopologicalSortAlgorithm

Topological Sort is a linear ordering of the vertices of a directed acyclic graph (DAG) such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering. It is commonly used in scheduling tasks with dependencies or resolving the order of compilation for a set of files with dependencies.

## Time Complexity

Best: O(V + E)
Average: O(V + E)
Worst: O(V + E)

## Space Complexity

O(V)

## Example Use Case

Finding a valid sequence for a set of tasks with dependencies, such as determining the order in which courses should be taken in a curriculum, or scheduling tasks in a project with precedence constraints.
