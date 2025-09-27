use std::collections::BinaryHeap;
use std::collections::HashMap;
use std::collections::HashSet;

#[derive(Debug, Eq, PartialEq, PartialOrd, Ord, Clone)]
struct Node {
    id: usize,
    cost: i32,
}

impl Node {
    fn new(id: usize, cost: i32) -> Node {
        Node { id, cost }
    }
}

fn dijkstra(graph: &HashMap<usize, Vec<(usize, i32)>>, start: usize) -> HashMap<usize, i32> {
    let mut distance: HashMap<usize, i32> = graph
        .keys()
        .map(|&id| (id, i32::max_value()))
        .collect();
    distance.insert(start, 0);

    let mut visited: HashSet<usize> = HashSet::new();

    let mut priority_queue: BinaryHeap<Node> = BinaryHeap::new();
    priority_queue.push(Node::new(start, 0));

    while let Some(Node { id, cost }) = priority_queue.pop() {
        if visited.contains(&id) {
            continue;
        }

        visited.insert(id);

        for &(neighbor, weight) in &graph[&id] {
            let new_cost = cost + weight;
            if new_cost < distance[&neighbor] {
                distance.insert(neighbor, new_cost);
                priority_queue.push(Node::new(neighbor, new_cost));
            }
        }
    }

    distance
}

fn main() {
    let mut graph: HashMap<usize, Vec<(usize, i32)> > = HashMap::new();
    graph.insert(0, vec![(1, 4), (2, 2)]);
    graph.insert(1, vec![(3, 5)]);
    graph.insert(2, vec![(1, 1), (3, 8)]);
    graph.insert(3, vec![]);

    let start_node = 0;
    let distances = dijkstra(&graph, start_node);

    for (node, distance) in distances.iter() {
        println!("Shortest distance from node {} to node {}: {}", start_node, node, distance);
    }
}