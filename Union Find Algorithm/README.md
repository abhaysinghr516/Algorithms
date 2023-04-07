# Union Find Algorithm

Union Find, also known as Disjoint Set, is a data structure and algorithm that keeps track of a set of elements partitioned into disjoint, non-overlapping subsets. It supports two primary operations: Union, which merges two subsets into a single subset, and Find, which determines the representative element of a subset.

## Time Complexity

Best: O(α(n)) for Union and Find operations with path compression and union by rank
Average: O(α(n)) for Union and Find operations with path compression and union by rank
Worst: O(α(n)) for Union and Find operations with path compression and union by rank

## Space Complexity

O(n)

## Example Use Case

Managing connected components in a graph, such as implementing Kruskal's algorithm for finding the minimum spanning tree or detecting cycles in an undirected graph.
