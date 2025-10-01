"""
Tree Traversal Algorithm Implementation in Python

This program demonstrates three types of binary tree traversals:
1. Preorder (Root -> Left -> Right)
2. Inorder (Left -> Root -> Right)  
3. Postorder (Left -> Right -> Root)
"""

class TreeNode:
    """Binary tree node class"""
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def preorder_traversal(node, result=None):
    """Preorder traversal: Root -> Left -> Right"""
    if result is None:
        result = []
    
    if node is not None:
        result.append(node.data)
        preorder_traversal(node.left, result)
        preorder_traversal(node.right, result)
    
    return result

def inorder_traversal(node, result=None):
    """Inorder traversal: Left -> Root -> Right"""
    if result is None:
        result = []
    
    if node is not None:
        inorder_traversal(node.left, result)
        result.append(node.data)
        inorder_traversal(node.right, result)
    
    return result

def postorder_traversal(node, result=None):
    """Postorder traversal: Left -> Right -> Root"""
    if result is None:
        result = []
    
    if node is not None:
        postorder_traversal(node.left, result)
        postorder_traversal(node.right, result)
        result.append(node.data)
    
    return result

def preorder_iterative(root):
    """Iterative preorder traversal using stack"""
    if not root:
        return []
    
    result = []
    stack = [root]
    
    while stack:
        node = stack.pop()
        result.append(node.data)
        
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)
    
    return result

def inorder_iterative(root):
    """Iterative inorder traversal using stack"""
    result = []
    stack = []
    current = root
    
    while current or stack:
        while current:
            stack.append(current)
            current = current.left
        
        current = stack.pop()
        result.append(current.data)
        current = current.right
    
    return result

def postorder_iterative(root):
    """Iterative postorder traversal using two stacks"""
    if not root:
        return []
    
    result = []
    stack1 = [root]
    stack2 = []
    
    while stack1:
        node = stack1.pop()
        stack2.append(node)
        
        if node.left:
            stack1.append(node.left)
        if node.right:
            stack1.append(node.right)
    
    while stack2:
        result.append(stack2.pop().data)
    
    return result

def main():
    """Example usage of tree traversal algorithms"""
    # Create a sample binary tree
    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5
    
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    
    print("Tree Traversal Algorithms:")
    print("Preorder traversal:", preorder_traversal(root))
    print("Inorder traversal:", inorder_traversal(root))
    print("Postorder traversal:", postorder_traversal(root))
    
    print("\nIterative implementations:")
    print("Preorder iterative:", preorder_iterative(root))
    print("Inorder iterative:", inorder_iterative(root))
    print("Postorder iterative:", postorder_iterative(root))

if __name__ == "__main__":
    main()