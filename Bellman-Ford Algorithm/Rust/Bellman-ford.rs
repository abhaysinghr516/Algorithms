/* The Bellman-Ford algorithm is used to find the shortest path from a source vertex to all other vertices in a weighted, directed graph. It can handle graphs with negative-weight edges, but it is not suitable for graphs with negative-weight cycles */

// Define a structure to represent an edge in the graph
struct Edge {
    source: usize,  // Source vertex of the edge
    destination: usize, // Destination vertex of the edge
    weight: i32, // Weight of the edge
}

// Define a structure to represent the graph
struct Graph {
    vertices: usize, // Number of vertices in the graph
    edges: Vec<Edge>, // List of edges in the graph
}

impl Graph {
    // Constructor for the Graph structure
    fn new(vertices: usize) -> Graph {
        Graph {
            vertices,
            edges: vec![],
        }
    }

    // Function to add an edge to the graph
    fn add_edge(&mut self, source: usize, destination: usize, weight: i32) {
        self.edges.push(Edge {
            source,
            destination,
            weight,
        });
    }

    // Function to perform the Bellman-Ford algorithm
    fn bellman_ford(&self, source: usize) -> Vec<i32> {
        // Initialize the distance array with a large value for all vertices
        let mut distances = vec![i32::MAX; self.vertices];
        distances[source] = 0; // Distance from the source to itself is 0

        // Relax all edges repeatedly to find the shortest paths
        for _ in 0..self.vertices - 1 {
            for edge in &self.edges {
                let u = edge.source;
                let v = edge.destination;
                let w = edge.weight;

                // Relax the edge if a shorter path is found
                if distances[u] != i32::MAX && distances[u] + w < distances[v] {
                    distances[v] = distances[u] + w;
                }
            }
        }

        // Check for negative-weight cycles
        for edge in &self.edges {
            let u = edge.source;
            let v = edge.destination;
            let w = edge.weight;

            if distances[u] != i32::MAX && distances[u] + w < distances[v] {
                panic!("Graph contains a negative-weight cycle");
            }
        }

        distances // Return the array of shortest distances
    }
}

fn main() {
    let vertices = 5;
    let mut graph = Graph::new(vertices);

    graph.add_edge(0, 1, -1);
    graph.add_edge(0, 2, 4);
    graph.add_edge(1, 2, 3);
    graph.add_edge(1, 3, 2);
    graph.add_edge(1, 4, 2);
    graph.add_edge(3, 2, 5);
    graph.add_edge(3, 1, 1);
    graph.add_edge(4, 3, -3);

    let source = 0;
    let distances = graph.bellman_ford(source);

    for (i, distance) in distances.iter().enumerate() {
        println!("Shortest distance from {} to {} is {}", source, i, distance);
    }
}
