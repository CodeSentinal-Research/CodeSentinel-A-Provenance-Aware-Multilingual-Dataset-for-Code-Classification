Here is the Python code for the problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def boundary_traversal(root):
    if root is None:
        return

    print(root.data, end=" ")

    left = root.left
    while left:
        print(left.data, end=" ")
        left = left.left

    leaf = root.left
    while leaf and leaf.right:
        leaf = leaf.right

    while leaf:
        print(leaf.data, end=" ")
        leaf = leaf.left

    right = root.right
    while right:
        right = right.right

        print(right.data, end=" ")

def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)

    boundary_traversal(root)

if __name__ == "__main__":
    main()
This program prints the boundary traversal of a binary tree. The boundary traversal of a binary tree is a list of nodes of the tree which are at the boundaries (root, left-most node, right-most node, leaf nodes).

In this program, Node class is used to create a node in the binary tree. The root of the binary tree is created in the main function. The boundary_traversal function is used to print the boundary traversal of the binary tree.

The left boundary of the binary tree is printed first, followed by the leaf nodes from left to right, and finally the right boundary of the binary tree is printed in reverse order.