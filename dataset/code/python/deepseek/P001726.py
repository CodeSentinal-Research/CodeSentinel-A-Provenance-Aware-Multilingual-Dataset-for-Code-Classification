Here is the Python code for the problem:

class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

def add_child(parent, child):
    parent.children.append(child)

def solve(N, node_values, tree_info, K):
    nodes = [Node(value) for value in node_values]
    for info in tree_info:
        parent, child, is_left = info
        if is_left:
            add_child(nodes[parent], nodes[child])
        else:
            add_child(nodes[child], nodes[parent])
    paths = [0]
    for node in nodes:
        paths = find_paths(node, K, paths)
    return paths[0]

def find_paths(node, K, paths):
    if node.value == K and not node.children:
        paths[0] += 1
    else:
        for child in node.children:
            paths = find_paths(child, K - node.value, paths)
    return paths

def main():
    N = int(input().strip())
    node_values = list(map(int, input().strip().split()))
    tree_info = []
    for _ in range(N-1):
        parent, child, is_left = map(int, input().strip().split())
        tree_info.append((parent, child, is_left))
    K = int(input().strip())
    print(solve(N, node_values, tree_info, K))

if __name__ == "__main__":
    main()

This program first reads the number of nodes N, followed by the node values. Then it reads the tree information, which is a list of tuples where each tuple contains the parent node index, child node index, and a boolean indicating whether the child node is to the left or right of the parent node. Finally, it reads the value K.

The `Node` class represents a node in the tree. The `add_child` function adds a child to a parent node.

The `solve` function creates a list of nodes and populates the tree by calling `add_child` for each edge. Then it finds all the paths in the tree whose values sum up to K.

The `find_paths` function recursively finds all paths in a node that sum up to K. It adds 1 to the count of paths if the node value is K and the node is a leaf node. Otherwise, it recursively calls `find_paths` for all children of the node.

The `main` function reads the problem input, calls `solve`, and prints the result.