Here is a Python solution for the problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def print_leaf_nodes(root):
    if root is None:
        return
    if root.left is None and root.right is None:
        print(root.data, end=" ")
    print_leaf_nodes(root.right)
    print_leaf_nodes(root.left)

def construct_tree(nodes, index):
    if index < len(nodes):
        if nodes[index] is not None:
            node = Node(nodes[index])
            index += 1
            node.left = construct_tree(nodes, index)
            node.right = construct_tree(nodes, index)
            return node
        else:
            return None
    return None

def main():
    n = int(input())
    nodes = list(map(int, input().split()))
    root = construct_tree(nodes, 0)
    print_leaf_nodes(root)

if __name__ == "__main__":
    main()

This code first constructs the binary tree from a list of integers. Then, it calls a recursive function `print_leaf_nodes` to print the leaf nodes in right-to-left order.

The `construct_tree` function is a recursive function that constructs a binary tree from a list of integers. It first checks if the current index is valid. If the node at the current index is not None, it creates a new node with the data at the current index and calls itself recursively for the left and right children. If the node at the current index is None, it returns None.

In the `main` function, it first reads the number of nodes and the nodes themselves. It then constructs the binary tree from these nodes and calls the `print_leaf_nodes` function to print the leaf nodes in right-to-left order.