import java.util.Arrays;

public class BellmanFord {

    private static final int V = 5;
    private static final int E = 8;
    private static final int INF = Integer.MAX_VALUE;

    public static void bellmanFord(int[][] graph) {
        int[] dist = new int[V];
        Arrays.fill(dist, INF);
        dist[0] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (int[] edge : graph) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        for (int i = 0; i < V; i++) {
            System.out.println("Distance from source to vertex " + i + ": " + dist[i]);
        }
    }

    public static void main(String[] args) {
        int[][] graph = {
                {0, 1, -1},
                {0, 2, 4},
                {1, 2, 3},
                {1, 3, 2},
                {1, 4, 2},
                {3, 2, 5},
                {3, 1, 1},
                {4, 3, -3}
        };

        bellmanFord(graph);
    }
}
