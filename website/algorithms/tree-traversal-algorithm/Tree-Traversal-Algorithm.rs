/*
Tree Traversal Algorithm Implementation in Rust

This program demonstrates three types of binary tree traversals:
1. Preorder (Root -> Left -> Right)
2. Inorder (Left -> Root -> Right)
3. Postorder (Left -> Right -> Root)
*/

use std::rc::Rc;
use std::cell::RefCell;

// TreeNode definition using Rc and RefCell for shared ownership
#[derive(Debug)]
pub struct TreeNode {
    pub data: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    pub fn new(data: i32) -> Self {
        TreeNode {
            data,
            left: None,
            right: None,
        }
    }
}

// Preorder traversal: Root -> Left -> Right
pub fn preorder_traversal(node: &Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
    if let Some(n) = node {
        let n = n.borrow();
        result.push(n.data);
        preorder_traversal(&n.left, result);
        preorder_traversal(&n.right, result);
    }
}

// Inorder traversal: Left -> Root -> Right
pub fn inorder_traversal(node: &Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
    if let Some(n) = node {
        let n = n.borrow();
        inorder_traversal(&n.left, result);
        result.push(n.data);
        inorder_traversal(&n.right, result);
    }
}

// Postorder traversal: Left -> Right -> Root
pub fn postorder_traversal(node: &Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
    if let Some(n) = node {
        let n = n.borrow();
        postorder_traversal(&n.left, result);
        postorder_traversal(&n.right, result);
        result.push(n.data);
    }
}

// Iterative preorder traversal using stack
pub fn preorder_iterative(root: &Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result = Vec::new();
    let mut stack = Vec::new();
    
    if let Some(root_node) = root {
        stack.push(root_node.clone());
    }
    
    while let Some(node) = stack.pop() {
        let node = node.borrow();
        result.push(node.data);
        
        if let Some(right) = &node.right {
            stack.push(right.clone());
        }
        if let Some(left) = &node.left {
            stack.push(left.clone());
        }
    }
    
    result
}

// Iterative inorder traversal using stack
pub fn inorder_iterative(root: &Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result = Vec::new();
    let mut stack = Vec::new();
    let mut current = root.clone();
    
    while current.is_some() || !stack.is_empty() {
        while let Some(node) = current {
            stack.push(node.clone());
            current = node.borrow().left.clone();
        }
        
        if let Some(node) = stack.pop() {
            result.push(node.borrow().data);
            current = node.borrow().right.clone();
        }
    }
    
    result
}

// Iterative postorder traversal using two stacks
pub fn postorder_iterative(root: &Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result = Vec::new();
    let mut stack1 = Vec::new();
    let mut stack2 = Vec::new();
    
    if let Some(root_node) = root {
        stack1.push(root_node.clone());
    }
    
    while let Some(node) = stack1.pop() {
        stack2.push(node.clone());
        
        let node_ref = node.borrow();
        if let Some(left) = &node_ref.left {
            stack1.push(left.clone());
        }
        if let Some(right) = &node_ref.right {
            stack1.push(right.clone());
        }
    }
    
    while let Some(node) = stack2.pop() {
        result.push(node.borrow().data);
    }
    
    result
}

fn main() {
    // Create a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    
    let root = Some(Rc::new(RefCell::new(TreeNode::new(1))));
    
    if let Some(root_node) = &root {
        root_node.borrow_mut().left = Some(Rc::new(RefCell::new(TreeNode::new(2))));
        root_node.borrow_mut().right = Some(Rc::new(RefCell::new(TreeNode::new(3))));
        
        if let Some(left_node) = &root_node.borrow().left {
            left_node.borrow_mut().left = Some(Rc::new(RefCell::new(TreeNode::new(4))));
            left_node.borrow_mut().right = Some(Rc::new(RefCell::new(TreeNode::new(5))));
        }
    }
    
    println!("Tree Traversal Algorithms:");
    
    // Recursive implementations
    let mut preorder_result = Vec::new();
    preorder_traversal(&root, &mut preorder_result);
    println!("Preorder traversal: {:?}", preorder_result);
    
    let mut inorder_result = Vec::new();
    inorder_traversal(&root, &mut inorder_result);
    println!("Inorder traversal: {:?}", inorder_result);
    
    let mut postorder_result = Vec::new();
    postorder_traversal(&root, &mut postorder_result);
    println!("Postorder traversal: {:?}", postorder_result);
    
    // Iterative implementations
    println!("\nIterative implementations:");
    println!("Preorder iterative: {:?}", preorder_iterative(&root));
    println!("Inorder iterative: {:?}", inorder_iterative(&root));
    println!("Postorder iterative: {:?}", postorder_iterative(&root));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_tree_traversals() {
        let root = Some(Rc::new(RefCell::new(TreeNode::new(1))));
        
        if let Some(root_node) = &root {
            root_node.borrow_mut().left = Some(Rc::new(RefCell::new(TreeNode::new(2))));
            root_node.borrow_mut().right = Some(Rc::new(RefCell::new(TreeNode::new(3))));
            
            if let Some(left_node) = &root_node.borrow().left {
                left_node.borrow_mut().left = Some(Rc::new(RefCell::new(TreeNode::new(4))));
                left_node.borrow_mut().right = Some(Rc::new(RefCell::new(TreeNode::new(5))));
            }
        }
        
        let mut preorder_result = Vec::new();
        preorder_traversal(&root, &mut preorder_result);
        assert_eq!(preorder_result, vec![1, 2, 4, 5, 3]);
        
        let mut inorder_result = Vec::new();
        inorder_traversal(&root, &mut inorder_result);
        assert_eq!(inorder_result, vec![4, 2, 5, 1, 3]);
        
        let mut postorder_result = Vec::new();
        postorder_traversal(&root, &mut postorder_result);
        assert_eq!(postorder_result, vec![4, 5, 2, 3, 1]);
    }
}