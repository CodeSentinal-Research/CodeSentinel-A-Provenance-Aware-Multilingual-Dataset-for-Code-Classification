Here is a Python solution using a simple Binary Tree implementation:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(node, data):
    if node is None:
        return Node(data)
    if data < node.data:
        node.left = insert(node.left, data)
    else:
        node.right = insert(node.right, data)
    return node

def printLeaves(root):
    if root is None:
        return
    printLeaves(root.left)
    if root.left is None and root.right is None:
        print(root.data)
    printLeaves(root.right)

def main():
    n = int(input())
    root = None
    for i in range(n):
        data = int(input())
        root = insert(root, data)
    printLeaves(root)

if __name__ == "__main__":
    main()

This code first reads the number of nodes from the input, then for each node, it reads the data and inserts it into the binary tree. After that, it prints all leaf nodes in left-to-right order.