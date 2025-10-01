/**
 * Tree Traversal Algorithm Implementation in JavaScript
 * 
 * This program demonstrates three types of binary tree traversals:
 * 1. Preorder (Root -> Left -> Right)
 * 2. Inorder (Left -> Root -> Right)  
 * 3. Postorder (Left -> Right -> Root)
 */

// TreeNode class definition
class TreeNode {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

// Preorder traversal: Root -> Left -> Right
function preorderTraversal(node, result = []) {
    if (node !== null) {
        result.push(node.data);
        preorderTraversal(node.left, result);
        preorderTraversal(node.right, result);
    }
    return result;
}

// Inorder traversal: Left -> Root -> Right
function inorderTraversal(node, result = []) {
    if (node !== null) {
        inorderTraversal(node.left, result);
        result.push(node.data);
        inorderTraversal(node.right, result);
    }
    return result;
}

// Postorder traversal: Left -> Right -> Root
function postorderTraversal(node, result = []) {
    if (node !== null) {
        postorderTraversal(node.left, result);
        postorderTraversal(node.right, result);
        result.push(node.data);
    }
    return result;
}

// Iterative implementations using stack
function preorderIterative(root) {
    if (!root) return [];

    const result = [];
    const stack = [root];

    while (stack.length > 0) {
        const node = stack.pop();
        result.push(node.data);

        if (node.right) stack.push(node.right);
        if (node.left) stack.push(node.left);
    }

    return result;
}

function inorderIterative(root) {
    const result = [];
    const stack = [];
    let current = root;

    while (current || stack.length > 0) {
        while (current) {
            stack.push(current);
            current = current.left;
        }
        current = stack.pop();
        result.push(current.data);
        current = current.right;
    }

    return result;
}

// Example usage
function main() {
    // Create a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    const root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);

    console.log("Tree Traversal Algorithms:");
    console.log("Preorder traversal:", preorderTraversal(root));
    console.log("Inorder traversal:", inorderTraversal(root));
    console.log("Postorder traversal:", postorderTraversal(root));

    console.log("\nIterative implementations:");
    console.log("Preorder iterative:", preorderIterative(root));
    console.log("Inorder iterative:", inorderIterative(root));
}

// Run the example
main();

// Export for use in other modules
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        TreeNode,
        preorderTraversal,
        inorderTraversal,
        postorderTraversal,
        preorderIterative,
        inorderIterative
    };
}