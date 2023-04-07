# Dijkstra's Algorithm

Dijkstra's Algorithm is a graph search algorithm that finds the shortest path from a source vertex to all other vertices in a weighted, directed graph with non-negative edge weights.

## Time Complexity

Best: O(V^2) with an adjacency matrix, O(V + E _ log(V)) with an adjacency list and a min-priority queue
Average: O(V^2) with an adjacency matrix, O(V + E _ log(V)) with an adjacency list and a min-priority queue
Worst: O(V^2) with an adjacency matrix, O(V + E \* log(V)) with an adjacency list and a min-priority queue

## Space Complexity

O(V)

## Example Use Case

Finding the shortest path from a source vertex to all other vertices in a graph with non-negative edge weights, such as shortest driving times between cities or lowest costs in a transportation network.
