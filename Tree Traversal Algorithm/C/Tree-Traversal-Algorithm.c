/*
 * Tree Traversal Algorithm Implementation in C
 * 
 * This program demonstrates three types of binary tree traversals:
 * 1. Preorder (Root -> Left -> Right)
 * 2. Inorder (Left -> Root -> Right)  
 * 3. Postorder (Left -> Right -> Root)
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder traversal: Root -> Left -> Right
void preorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

// Postorder traversal: Left -> Right -> Root
void postorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    // Create a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    printf("Tree Traversal Algorithms:\n");
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    return 0;
}