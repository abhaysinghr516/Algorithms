use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Copy, Clone, Eq, PartialEq)]
struct Node {
    id: usize,
    distance: u32,
}

impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        other.distance.cmp(&self.distance)
    }
}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn dijkstra(graph: &[Vec<(usize, u32)>], start: usize) -> Vec<u32> {
    let mut distances = vec![u32::MAX; graph.len()];
    let mut heap = BinaryHeap::new();

    distances[start] = 0;
    heap.push(Node { id: start, distance: 0 });

    while let Some(Node { id, distance }) = heap.pop() {
        if distance > distances[id] {
            continue;
        }

        for &(neighbor, weight) in &graph[id] {
            let new_distance = distance + weight;
            if new_distance < distances[neighbor] {
                distances[neighbor] = new_distance;
                heap.push(Node { id: neighbor, distance: new_distance });
            }
        }
    }

    distances
}

fn main() {
    // 构建一个图的邻接表表示
    let graph = vec![
        vec![(1, 7), (2, 9), (5, 14)],
        vec![(0, 7), (2, 10), (3, 15)],
        vec![(0, 9), (1, 10), (3, 11), (5, 2)],
        vec![(1, 15), (2, 11), (4, 6)],
        vec![(3, 6), (5, 9)],
        vec![(0, 14), (2, 2), (4, 9)],
    ];

    let start_node = 0;
    let distances = dijkstra(&graph, start_node);

    for (i, distance) in distances.iter().enumerate() {
        println!("Distance from node {} to node {}: {}", start_node, i, distance);
    }
}
