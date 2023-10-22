#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;       // Number of vertices and edges
    struct Edge* edge;
};

// Create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Compare function used to sort edges based on their weights
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Find set of an element 'i'
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Union of two sets of x and y
void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Kruskal's algorithm to find Minimum Spanning Tree
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];  // This will store the resultant MST
    int e = 0;              // Index variable for result[]
    int i = 0;              // Index variable for sorted edges

    // Sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    int* parent = (int*)malloc(V * sizeof(int));
    // Initialize all subsets as single element sets
    for (int v = 0; v < V; v++) {
        parent[v] = -1;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1) {
        struct Edge nextEdge = graph->edge[i++];
        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        // If including this edge doesn't cause a cycle, include it
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, x, y);
        }
    }

    // Print the edges of MST
    printf("Edges of Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(parent);
}

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // Add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // Add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // Add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // Add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    kruskalMST(graph);

    return 0;
}
