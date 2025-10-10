#include <stdio.h>
#include <limits.h>

#define V 5

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++)
        if(mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    int parent[V], key[V], mstSet[V];
    for(int i = 0; i < V; i++) key[i] = INT_MAX, mstSet[i] = 0;
    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for(int v = 0; v < V; v++)
            if(graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    for(int i = 1; i < V; i++)
        printf("%d - %d\n", parent[i], i);

    return 0;
}
