import java.util.ArrayList;
import java.util.List;

public class DepthFirstSearch {
    static class Graph {
        int vertices;
        List<List<Integer>> adjList;
        boolean[] visited;

        public Graph(int vertices) {
            this.vertices = vertices;
            adjList = new ArrayList<>(vertices);
            visited = new boolean[vertices];

            for (int i = 0; i < vertices; i++) {
                adjList.add(new ArrayList<>());
            }
        }

        public void addEdge(int src, int dest) {
            adjList.get(src).add(dest);
            adjList.get(dest).add(src);
        }

        public void dfs(int vertex) {
            visited[vertex] = true;
            System.out.println("Visited " + vertex);

            for (int adjVertex : adjList.get(vertex)) {
                if (!visited[adjVertex]) {
                    dfs(adjVertex);
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

        g.dfs(0);
    }
}
