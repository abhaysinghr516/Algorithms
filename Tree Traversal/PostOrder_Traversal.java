// Description

// Postorder traversal is a way to visit and process the nodes in a tree data structure.
// In postorder traversal, you start at the root node, recursively traverse the left subtree,
// then recursively traverse the right subtree, and finally, visit the current node.
// Here's a Java implementation of postorder traversal for a binary tree:


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

public class PostorderTraversal {
    public static void postorderTraversal(TreeNode node) {
        if (node != null) {
            // Recursively traverse the left subtree
            postorderTraversal(node.left);
            
            // Recursively traverse the right subtree
            postorderTraversal(node.right);
            
            // Visit the current node
            System.out.print(node.data + " ");
        }
    }

    public static void main(String[] args) {
        // Create a simple binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.print("Postorder traversal: ");
        postorderTraversal(root);
    }
}
