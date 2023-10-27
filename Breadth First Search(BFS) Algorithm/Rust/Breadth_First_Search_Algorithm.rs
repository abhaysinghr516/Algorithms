use std::collections::{LinkedList, VecDeque};

struct Graph {
    vertices: usize,
    adj_list: Vec<LinkedList<usize>>,
}

impl Graph {
    fn new(vertices: usize) -> Graph {
        let mut adj_list = vec![LinkedList::new(); vertices];
        Graph { vertices, adj_list }
    }

    fn add_edge(&mut self, src: usize, dest: usize) {
        self.adj_list[src].push_back(dest);
        self.adj_list[dest].push_back(src);
    }

    fn bfs(&self, start_vertex: usize) {
        let mut visited = vec![false; self.vertices];
        let mut queue = VecDeque::new();

        visited[start_vertex] = true;
        queue.push_back(start_vertex);

        while let Some(current_vertex) = queue.pop_front() {
            println!("Visited {}", current_vertex);

            for &adj_vertex in &self.adj_list[current_vertex] {
                if !visited[adj_vertex] {
                    visited[adj_vertex] = true;
                    queue.push_back(adj_vertex);
                }
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

    g.bfs(0);
}
