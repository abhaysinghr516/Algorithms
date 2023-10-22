class Graph {
  constructor(vertices) {
    this.V = vertices;
    this.graph = [];
  }

  addEdge(u, v, w) {
    this.graph.push([u, v, w]);
  }

  kruskalMST() {
    // Sort the edges in ascending order of their weights
    this.graph.sort((a, b) => a[2] - b[2]);

    let parent = Array(this.V).fill(-1);

    function find(parent, i) {
      if (parent[i] === -1) return i;
      return find(parent, parent[i]);
    }

    function union(parent, x, y) {
      let xSet = find(parent, x);
      let ySet = find(parent, y);
      parent[xSet] = ySet;
    }

    let result = [];
    let e = 0;
    let i = 0;

    while (e < this.V - 1) {
      let [u, v, w] = this.graph[i];
      i++;

      let x = find(parent, u);
      let y = find(parent, v);

      if (x !== y) {
        result.push([u, v, w]);
        e++;
        union(parent, x, y);
      }
    }

    return result;
  }
}

// Example usage:
const vertices = 4;
const graph = new Graph(vertices);

graph.addEdge(0, 1, 10);
graph.addEdge(0, 2, 6);
graph.addEdge(0, 3, 5);
graph.addEdge(1, 3, 15);
graph.addEdge(2, 3, 4);

const minimumSpanningTree = graph.kruskalMST();
console.log("Minimum Spanning Tree:");
console.log(minimumSpanningTree);
