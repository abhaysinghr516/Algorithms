class Graph {
    constructor(vertices) {
        this.vertices = vertices;
        this.adjList = new Array(vertices).fill(null).map(() => []);
        this.visited = new Array(vertices).fill(false);
    }

    addEdge(src, dest) {
        this.adjList[src].push(dest);
        this.adjList[dest].push(src);
    }

    dfs(vertex) {
        this.visited[vertex] = true;
        console.log("Visited", vertex);

        for (const adjVertex of this.adjList[vertex]) {
            if (!this.visited[adjVertex]) {
                this.dfs(adjVertex);
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

g.dfs(0);
