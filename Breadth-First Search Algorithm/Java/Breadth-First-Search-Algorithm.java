import java.util.*;

public class BFS {
    static class Graph {
        int vertices;
        LinkedList<Integer>[] adj_list;

        Graph(int vertices) {
            this.vertices = vertices;
            adj_list = new LinkedList[vertices];

            for (int i = 0; i < vertices; i++) {
                adj_list[i] = new LinkedList<>();
            }
        }

        void addEdge(int src, int dest) {
            adj_list[src].add(dest);
            adj_list[dest].add(src);
        }

        void bfs(int start_vertex) {
            boolean[] visited = new boolean[vertices];
            Queue<Integer> queue = new LinkedList<>();

            visited[start_vertex] = true;
            queue.add(start_vertex);

            while (!queue.isEmpty()) {
                int current_vertex = queue.poll();
                System.out.println("Visited " + current_vertex);

                for (int adj_vertex : adj_list[current_vertex]) {
                    if (!visited[adj_vertex]) {
                        visited[adj_vertex] = true;
                        queue.add(adj_vertex);
                                            }
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(6);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 4);
        g.addEdge(3, 5);
        g.addEdge(4, 5);

        g.bfs(0);
    }
}
