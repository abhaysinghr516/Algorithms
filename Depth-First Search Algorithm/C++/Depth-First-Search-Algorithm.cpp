#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    Graph(int vertices) : vertices(vertices) {
        adj_list.resize(vertices);
        visited.resize(vertices, false);
    }

    void add_edge(int src, int dest) {
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
    }

    void dfs(int vertex) {
        visited[vertex] = true;
        std::cout << "Visited " << vertex << std::endl;

        for (int adj_vertex : adj_list[vertex]) {
            if (!visited[adj_vertex]) {
                dfs(adj_vertex);
            }
        }
    }

private:
    int vertices;
    std::vector<std::list<int>> adj_list;
    std::vector<bool> visited;
};

int main() {
    Graph g(6);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(3, 5);
    g.add_edge(4, 5);

    g.dfs(0);

    return 0;
}
