#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph {
public:
    Graph(int vertices) : vertices(vertices) {
        adj_list.resize(vertices);
    }

    void add_edge(int src, int dest) {
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
    }

    void bfs(int start_vertex) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;

        visited[start_vertex] = true;
        q.push(start_vertex);

        while (!q.empty()) { 
                        int current_vertex = q.front();
            q.pop();

            std::cout << "Visited " << current_vertex << std::endl;

            for (int adj_vertex : adj_list[current_vertex]) {
                if (!visited[adj_vertex]) {
                    visited[adj_vertex] = true;
                    q.push(adj_vertex);
                }
            }
        }
    }

private:
    int vertices;
    std::vector<std::list<int>> adj_list;
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

    g.bfs(0);

    return 0;
}
