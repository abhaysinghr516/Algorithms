struct Graph {
    vertices: usize,
    adj_list: Vec<Vec<usize>>,
}

impl Graph {
    fn new(vertices: usize) -> Self {
        let adj_list = vec![vec![]; vertices];
        Graph {
            vertices,
            adj_list,
        }
    }

    fn add_edge(&mut self, src: usize, dest: usize) {
        self.adj_list[src].push(dest);
        self.adj_list[dest].push(src);
    }

    fn dfs(&self, vertex: usize, visited: &mut Vec<bool>) {
        visited[vertex] = true;
        println!("Visited {}", vertex);

        for &adj_vertex in &self.adj_list[vertex] {
            if !visited[adj_vertex] {
                self.dfs(adj_vertex, visited);
            }
        }
    }
}

fn main() {
    let mut g = Graph::new(6);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(3, 5);
    g.add_edge(4, 5);

    let mut visited = vec![false; g.vertices];
    g.dfs(0, &mut visited);
}
