/*
Tree Traversal Algorithm Implementation in Go

This program demonstrates three types of binary tree traversals:
1. Preorder (Root -> Left -> Right)
2. Inorder (Left -> Root -> Right)
3. Postorder (Left -> Right -> Root)
*/

package main

import "fmt"

// TreeNode represents a node in a binary tree
type TreeNode struct {
	Data  int
	Left  *TreeNode
	Right *TreeNode
}

// NewTreeNode creates a new tree node
func NewTreeNode(data int) *TreeNode {
	return &TreeNode{
		Data:  data,
		Left:  nil,
		Right: nil,
	}
}

// PreorderTraversal performs preorder traversal: Root -> Left -> Right
func PreorderTraversal(node *TreeNode, result *[]int) {
	if node != nil {
		*result = append(*result, node.Data)
		PreorderTraversal(node.Left, result)
		PreorderTraversal(node.Right, result)
	}
}

// InorderTraversal performs inorder traversal: Left -> Root -> Right
func InorderTraversal(node *TreeNode, result *[]int) {
	if node != nil {
		InorderTraversal(node.Left, result)
		*result = append(*result, node.Data)
		InorderTraversal(node.Right, result)
	}
}

// PostorderTraversal performs postorder traversal: Left -> Right -> Root
func PostorderTraversal(node *TreeNode, result *[]int) {
	if node != nil {
		PostorderTraversal(node.Left, result)
		PostorderTraversal(node.Right, result)
		*result = append(*result, node.Data)
	}
}

// PreorderIterative performs iterative preorder traversal using stack
func PreorderIterative(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	result := []int{}
	stack := []*TreeNode{root}

	for len(stack) > 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		result = append(result, node.Data)

		if node.Right != nil {
			stack = append(stack, node.Right)
		}
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
	}

	return result
}

// InorderIterative performs iterative inorder traversal using stack
func InorderIterative(root *TreeNode) []int {
	result := []int{}
	stack := []*TreeNode{}
	current := root

	for current != nil || len(stack) > 0 {
		for current != nil {
			stack = append(stack, current)
			current = current.Left
		}

		current = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		result = append(result, current.Data)
		current = current.Right
	}

	return result
}

// PostorderIterative performs iterative postorder traversal using two stacks
func PostorderIterative(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	result := []int{}
	stack1 := []*TreeNode{root}
	stack2 := []*TreeNode{}

	for len(stack1) > 0 {
		node := stack1[len(stack1)-1]
		stack1 = stack1[:len(stack1)-1]
		stack2 = append(stack2, node)

		if node.Left != nil {
			stack1 = append(stack1, node.Left)
		}
		if node.Right != nil {
			stack1 = append(stack1, node.Right)
		}
	}

	for len(stack2) > 0 {
		node := stack2[len(stack2)-1]
		stack2 = stack2[:len(stack2)-1]
		result = append(result, node.Data)
	}

	return result
}

func main() {
	// Create a sample binary tree
	//       1
	//      / \
	//     2   3
	//    / \
	//   4   5

	root := NewTreeNode(1)
	root.Left = NewTreeNode(2)
	root.Right = NewTreeNode(3)
	root.Left.Left = NewTreeNode(4)
	root.Left.Right = NewTreeNode(5)

	fmt.Println("Tree Traversal Algorithms:")

	// Recursive implementations
	preorderResult := []int{}
	PreorderTraversal(root, &preorderResult)
	fmt.Println("Preorder traversal:", preorderResult)

	inorderResult := []int{}
	InorderTraversal(root, &inorderResult)
	fmt.Println("Inorder traversal:", inorderResult)

	postorderResult := []int{}
	PostorderTraversal(root, &postorderResult)
	fmt.Println("Postorder traversal:", postorderResult)

	// Iterative implementations
	fmt.Println("\nIterative implementations:")
	fmt.Println("Preorder iterative:", PreorderIterative(root))
	fmt.Println("Inorder iterative:", InorderIterative(root))
	fmt.Println("Postorder iterative:", PostorderIterative(root))
}