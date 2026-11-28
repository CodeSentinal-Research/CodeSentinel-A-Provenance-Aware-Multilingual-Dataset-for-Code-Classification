Sure, here is the python code for the problem.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def diagonal(root, d):
    if root is None:
        return
    d[0] += root.data
    if root.left is None and root.right is None:
        print(d[0])
        return
    diagonal(root.left, d)
    diagonal(root.right, d)

def diagonalTraversal(root):
    d = [0]
    diagonal(root, d)

def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(7)
    root.left.right = Node(6)
    root.right.left = Node(5)
    root.right.right = Node(4)
    diagonalTraversal(root)

if __name__ == "__main__":
    main()

This code creates a binary tree and traverses it diagonally from top-right to bottom-left, printing the values as it goes.

In the main function, we create a binary tree with the given inputs, and then call the `diagonalTraversal` function to print the diagonal traversal.