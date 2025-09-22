const V = 5;
const E = 8;
const INF = Infinity;

function bellmanFord(graph) {
    const dist = Array(V).fill(INF);
    dist[0] = 0;

    for (let i = 0; i < V - 1; i++) {
        for (const edge of graph) {
            const [u, v, weight] = edge;
            if (dist[u] !== INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (let i = 0; i < V; i++) {
        console.log(`Distance from source to vertex ${i}: ${dist[i]}`);
    }
}

const graph = [
    [0, 1, -1],
    [0, 2, 4],
    [1, 2, 3],
    [1, 3, 2],
    [1, 4, 2],
    [3, 2, 5],
    [3, 1, 1],
    [4, 3, -3]
];

bellmanFord(graph);
