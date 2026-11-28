Here is the Python code:


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def print_boundary(root):
    if root is None:
        return

    print(root.data, end=' ')

    left = root.left
    while left:
        print(left.data, end=' ')
        left = left.left

    right = root.right
    while right:
        print(right.data, end=' ')
        right = right.right


if __name__ == '__main__':
    root = Node(20)
    root.left = Node(8)
    root.right = Node(22)
    root.left.left = Node(5)
    root.left.right = Node(12)
    root.left.right.left = Node(10)
    root.left.right.right = Node(14)
    root.right.left = Node(25)
    root.right.right = Node(27)

    print("Boundary order traversal: ", end=' ')
    print_boundary(root)

This code first creates a binary tree and then prints the exterior boundary of the tree in clockwise order. The boundary is printed from the root to the furthest leaf node. The left and right children of each node are then printed in reverse order to get the nodes on the outside.

This code assumes that you have a class `Node` defined to represent a node in the binary tree. The `print_boundary` function takes a root node as input and prints the exterior boundary of the binary tree in clockwise order.