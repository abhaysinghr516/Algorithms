# Kruskal's algorithm to find MST based on Union-Find implemented in Python

import sys

# Create a class to represent a graph
class Graph:
    def __init__(self, n) -> None:
        self.n = n
        self.graph = []

    # add edge to graph
    def add_edge(self, v1, v2, cost) -> None:
        self.graph.append([v1,v2,cost])

    def is_valid(self) -> bool:
        vert_set = set(list(range(self.n)))
        graph_set = set()
        for [v1, v2, c] in self.graph:
            graph_set.add(v1)
            graph_set.add(v2)
        if vert_set == graph_set:
            return True
        else:
            return False


    # find set of node v
    def find(self, parents, v) -> int:
        if parents[v] == v:
            return v
        return self.find(parents, parents[v])
    
    # does union of 2 sets of nodes v1 and v2 by rank
    def union(self, parents, rank, v1, v2):
        v1r = self.find(parents, v1)
        v2r = self.find(parents, v2)
        if rank[v1r] == rank[v2r]:
            parents[v2r] = v1r
            rank[v1r] += 1
        elif rank[v1r] > rank[v2r]:
            parents[v2r] = v1r
        else:
            parents[v1r] = v2r

    # constructs MST using Kruskal's Algorithm
    def kruskals(self) -> list:
        MST = []

        # order edges by cost
        ordered_edges = sorted(self.graph, key=lambda x: x[2])

        parents = []
        rank = []
        # intialize sets for all of the nodes
        for node in range(self.n):
            parents.append(node)
            rank.append(0)
        
        nodes = 0
        i = 0
        # run loop until all nodes have been encountered by MST
        while nodes < self.n - 1:
            v1, v2, cost = ordered_edges[i]
            i = i + 1
            v1r = self.find(parents, v1)
            v2r = self.find(parents, v2)
            # check if v1 and v2 are in different clusters (no cycle creation)
            if v1r != v2r:
                nodes = nodes + 1
                MST.append([v1, v2, cost])
                # combine the sets of v1 and v2 using union-rank
                self.union(parents, rank, v1r, v2r)
        return MST

def main():
    n = int(input("Enter the number of vertices for the graph as an integer): "))
    g = Graph(n)

    print("Now begin entering edges as prompted.")
    print("The edge should be formatted as 3 numbers (index of v1 and index of v2 and the cost) separated by one space in between.")
    print("EXAMPLE: edge connecting vertices 4 and 6 with cost 13.2 should be entered like this: 4 6 13.2")
    print("Type quit if there are no more edges")
    e_s = input("Enter edge: ")
    while e_s != "quit":
        e_l = e_s.split(" ")
        v1 = int(e_l[0])
        v2 = int(e_l[1])
        cost = float(e_l[2])
        g.add_edge(v1, v2, cost)
        e_s  = input("Enter edge: ")
    if not g.is_valid():
        print("The edges entered do not consitute a connected graph of " + str(g.n) + " vertices")
    else:
        MST = g.kruskals()
        print("Here is a list representation of the edges that make up the MST of the input graph")
        print(MST)

main()

# Example Test Case 1 
    # Graph
        # g = Graph(6)
        # g.add_edge(0, 1, 4)
        # g.add_edge(0, 2, 4)
        # g.add_edge(1, 2, 2)
        # g.add_edge(1, 0, 4)
        # g.add_edge(2, 0, 4)
        # g.add_edge(2, 1, 2)
        # g.add_edge(2, 3, 3)
        # g.add_edge(2, 5, 2)
        # g.add_edge(2, 4, 4)
        # g.add_edge(3, 2, 3)
        # g.add_edge(3, 4, 3)
        # g.add_edge(4, 2, 4)
        # g.add_edge(4, 3, 3)
        # g.add_edge(5, 2, 2)
        # g.add_edge(5, 4, 3)

    #MST
        # [[1, 2, 2], [2, 5, 2], [2, 3, 3], [3, 4, 3], [0, 1, 4]]
