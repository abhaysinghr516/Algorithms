#include <iostream>
#include <limits>
#include <vector>

#define V 9

int min_distance(const std::vector<int>& dist, const std::vector<bool>& spt_set) {
    int min = std::numeric_limits<int>::max(), min_index;
    for (int v = 0; v < V; v++) {
        if (spt_set[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;    

}

void print_solution(const std::vector<int>& dist) {
    std::cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        std::cout << i << " \t\t " << dist[i] << '\n';
    }
}

void dijkstra(const std::vector<std::vector<int>>& graph, int src) {
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    std::vector<bool> spt_set(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, spt_set);
        spt_set[u] = true;

        for (int v = 0; v < V; v++) {
            if (!spt_set[v] && graph[u][v] && dist[u] != std::numeric_limits<int>::max() &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print_solution(dist);
}

int main() {
    std::vector<std::vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                           {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                           {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                           {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
