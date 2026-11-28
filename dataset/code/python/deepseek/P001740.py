Sure, here is a Python solution for the problem:

class Node:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

def remove_leaves(root):
    nodes_removed = []
    while root:
        leaf_nodes = set()
        while root.left or root.right:
            if root.left:
                leaf_nodes.add(root.left.data)
                root.left = root.left.left
            if root.right:
                leaf_nodes.add(root.right.data)
                root.right = root.right.right
        for node in leaf_nodes:
            nodes_removed.append(node)
        if not root.left and not root.right:
            root = None
        else:
            root = root.left if root.left else root.right
    return nodes_removed

def build_tree(input_list):
    nodes = [None if value is None else Node(value) for value in input_list]
    for index, node in enumerate(nodes):
        if node:
            if index % 2 == 0:
                nodes[index // 2].left = node
            else:
                nodes[index // 2].right = node
    return nodes[0]

def main():
    N = int(input())
    input_list = list(map(int, input().split()))
    root = build_tree(input_list)
    nodes_removed = remove_leaves(root)
    print('\n'.join(map(str, nodes_removed)))

if __name__ == "__main__":
    main()

In this solution, we first create a `Node` class to represent each node in the tree. Each node has a data value and two pointers to its left and right child.

The `remove_leaves` function iteratively removes the leaf nodes from the tree. In each round, it finds all the leaf nodes and removes them. The function returns a list of the nodes removed.

The `build_tree` function builds the tree from the input list. It first creates nodes, then connects them in the tree.

The `main` function is the entry point of the program. It reads the number of nodes and the list of nodes from the input, builds the tree, removes the leaf nodes, and prints the nodes removed.