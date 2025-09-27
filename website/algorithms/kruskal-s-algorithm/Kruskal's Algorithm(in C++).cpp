#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
class Graph {
public:
    int V, E;            // Number of vertices and edges
    vector<Edge> edge;   // Vector to store edges

    // Constructor
    Graph(int v, int e) {
        V = v;
        E = e;
        edge.resize(E);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        edge.push_back({src, dest, weight});
    }

    // Function to find the parent of a vertex
    int findParent(int parent[], int i) {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

    // Function to perform union of two sets
    void unionSets(int parent[], int x, int y) {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        parent[xset] = yset;
    }

    // Function to run Kruskal's algorithm and find the minimum spanning tree
    void kruskalMST() {
        vector<Edge> result; // Vector to store the resultant MST

        // Sort all the edges in non-decreasing order of their weight
        sort(edge.begin(), edge.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        int* parent = new int[V];
        fill(parent, parent + V, -1);

        for (Edge currentEdge : edge) {
            int x = findParent(parent, currentEdge.src);
            int y = findParent(parent, currentEdge.dest);

            // If including this edge doesn't create a cycle, add it to the MST
            if (x != y) {
                result.push_back(currentEdge);
                unionSets(parent, x, y);
            }
        }

        // Print the edges of the MST
        cout << "Edges of Minimum Spanning Tree:" << endl;
        for (Edge edge : result) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        }

        delete[] parent;
    }
};

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges
    Graph graph(V, E);

    // Add edges to the graph
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Find and print the Minimum Spanning Tree using Kruskal's algorithm
    graph.kruskalMST();

    return 0;
}
