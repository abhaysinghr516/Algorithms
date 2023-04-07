#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void bellmanFord(const vector<vector<int>>& graph, int V, int E) {
    vector<int> dist(V, INF);
    dist[0] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (const auto& edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << "Distance from source to vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int V = 5, E = 8;

    bellmanFord(graph, V, E);

    return 0;
}
