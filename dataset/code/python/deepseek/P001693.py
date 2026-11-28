Here is the Python code for the problem:

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def build_tree(nodes):
    node_list = [Node(val) for val in nodes]
    for i in range(len(node_list)):
        node_list[i].left = node_list[i * 2 + 1] if i * 2 + 1 < len(node_list) else None
        node_list[i].right = node_list[i * 2 + 2] if i * 2 + 2 < len(node_list) else None
    return node_list[0]

def longest_unival_path(root):
    def recurse(node):
        if not node:
            return 0
        left = recurse(node.left)
        right = recurse(node.right)
        left_unival = right_unival = 0
        if node.left and node.left.value == node.value:
            left_unival = left + 1
        if node.right and node.right.value == node.value:
            right_unival = right + 1
        return max(left_unival, right_unival, left + right)
    return max(recurse(root), recurse(root.left), recurse(root.right))

def main():
    nodes = list(map(int, input().split()))
    root = build_tree(nodes)
    print(longest_unival_path(root))

if __name__ == "__main__":
    main()

This program first reads the number of nodes and the node values from the input. It then constructs the binary tree from the node values. The `longest_unival_path` function is recursive and computes the length of the longest univalue path in the tree. It maintains three lengths for the univalue paths from left, right, and the current node. The maximum of these lengths is then the longest univalue path.

In the `main` function, it reads the input, constructs the tree, and prints the longest univalue path.