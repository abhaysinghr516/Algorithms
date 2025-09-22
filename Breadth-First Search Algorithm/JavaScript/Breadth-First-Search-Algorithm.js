class Graph {
    constructor(vertices) {
        this.vertices = vertices;
        this.adj_list = new Array(vertices).fill(null).map(() => []);
    }

    addEdge(src, dest) {
        this.adj_list[src].push(dest);
        this.adj_list[dest].push(src);
    }

    bfs(start_vertex) {
        const visited = new Array(this.vertices).fill(false);
        const queue = [start_vertex];

        visited[start_vertex] = true;

        while (queue.length > 0) {
            const current_vertex = queue.shift();
            console.log("Visited", current_vertex);

            for (const adj_vertex of this.adj_list[current_vertex]) {
                if (!visited[adj_vertex]) {
                    visited[adj_vertex] = true;
                    queue.push(adj_vertex);
                }
            }
        }
    }
}

const g = new Graph(6);

g.addEdge(0, 1);
g.addEdge(0, 2);
g.addEdge(1, 3);
g.addEdge(1, 4);
g.addEdge(2, 4);
g.addEdge(3, 5);
g.addEdge(4, 5);

g.bfs(0);
