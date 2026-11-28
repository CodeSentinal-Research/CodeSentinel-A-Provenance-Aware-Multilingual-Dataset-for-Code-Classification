Sure, here is a Python code for the problem:

def solve(node):
    if node is None:
        return 0
    if node.left is None and node.right is None:
        return 1
    return solve(node.left) + solve(node.right)

def count_paths(root):
    total = solve(root)
    print(total)

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree(nodes, idx, n):
    if idx > n:
        return None
    node = Node(nodes[idx])
    node.left = build_tree(nodes, 2 * idx, n)
    node.right = build_tree(nodes, 2 * idx + 1, n)
    return node

def main():
    n = 8
    nodes = [i for i in range(1, 9)]
    root = build_tree(nodes, 1, n)
    count_paths(root)

if __name__ == "__main__":
    main()

This code creates a binary tree using the input list of nodes. The `count_paths` function calls the `solve` function to count the total number of root-to-leaf paths. The `solve` function recursively counts the paths from the root to the leaf.

The `main` function is the entry point of the program. It creates a binary tree with the given nodes and counts the total number of root-to-leaf paths.