Here is the Python code with the main function and input handling.

from collections import Counter

def count_nodes(root, nodes):
    if root is None:
        return
    if root.val in nodes:
        nodes.remove(root.val)
    count_nodes(root.left, nodes)
    count_nodes(root.right, nodes)

def find_modes(root):
    count = Counter()
    count_nodes(root, list(count.keys()))
    max_count = max(count.values())
    modes = [k for k, v in count.items() if v == max_count]
    modes.sort()
    return modes

class Node:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree(nodes):
    if not nodes:
        return None
    val = nodes.pop(0)
    if val == 'N':
        return None
    node = Node(int(val))
    node.left = build_tree(nodes)
    node.right = build_tree(nodes)
    return node

def main():
    n = int(input().strip())
    nodes = [input().strip() for _ in range(n)]
    root = build_tree(nodes)
    modes = find_modes(root)
    print('\n'.join(map(str, modes)))

if __name__ == "__main__":
    main()

In this code, we first define a class `Node` for the binary tree nodes, and a function `build_tree(nodes)` to create a binary tree from a list of node values. Then we define the `find_modes(root)` function to find the modes in the binary tree. Finally, we define the `main()` function to read the input, build the binary tree, find the modes, and print the modes.