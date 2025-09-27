// Description

// Preorder traversal is a way to visit and process the nodes in a tree data structure.
// In preorder traversal, you start at the root node, visit the current node,
// then recursively traverse the left subtree, and finally, recursively traverse the right subtree.
// Here's a Java implementation of preorder traversal for a binary tree:

// implementation

class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;

    public TreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class PreorderTraversal {
    public static void preorderTraversal(TreeNode node) {
        if (node != null) {
            // Visit the current node
            System.out.print(node.data + " ");
            
            // Recursively traverse the left subtree
            preorderTraversal(node.left);
            
            // Recursively traverse the right subtree
            preorderTraversal(node.right);
        }
    }

    public static void main(String[] args) {
        // Create a simple binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.print("Preorder traversal: ");
        preorderTraversal(root);
    }
}
