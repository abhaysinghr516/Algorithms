use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Debug)]
struct Node {
    data: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(data: i32) -> Self {
        Node {
            data,
            left: None,
            right: None,
        }
    }
}

impl PartialEq for Node {
    fn eq(&self, other: &Self) -> bool {
        self.data == other.data
    }
}

impl Eq for Node {}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        other.data.cmp(&self.data) // Reverse order for min heap
    }
}

fn pre_order(root: &Option<Box<Node>>, s: String, ans: &mut Vec<String>) {
    if let Some(node) = root {
        if node.left.is_none() && node.right.is_none() {
            ans.push(s);
            return;
        }
        
        pre_order(&node.left, s.clone() + "0", ans);
        pre_order(&node.right, s + "1", ans);
    }
}

fn huffman_codes(frequencies: Vec<i32>) -> Vec<String> {
    let mut min_heap = BinaryHeap::new();
    
    for freq in frequencies {
        let node = Box::new(Node::new(freq));
        min_heap.push(node);
    }
    
    while min_heap.len() > 1 {
        let left = min_heap.pop().unwrap();
        let right = min_heap.pop().unwrap();
        
        let mut parent = Box::new(Node::new(left.data + right.data));
        parent.left = Some(left);
        parent.right = Some(right);
        
        min_heap.push(parent);
    }
    
    let root = min_heap.pop().unwrap();
    
    let mut ans = Vec::new();
    if root.left.is_none() && root.right.is_none() {
        ans.push("0".to_string());
    } else {
        pre_order(&Some(root), String::new(), &mut ans);
    }
    
    ans
}

fn main() {
    let frequencies = vec![5, 9, 12, 13, 16, 45];
    
    let codes = huffman_codes(frequencies.clone());
    
    print!("Frequencies: ");
    for freq in &frequencies {
        print!("{} ", freq);
    }
    println!();
    
    print!("Huffman codes: ");
    for code in &codes {
        print!("{} ", code);
    }
    println!();
    
    for (i, code) in codes.iter().enumerate() {
        println!("Frequency {} -> Code: {}", frequencies[i], code);
    }
}