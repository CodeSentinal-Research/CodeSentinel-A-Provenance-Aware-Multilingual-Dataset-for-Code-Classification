Here is a Python solution for the problem:

from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def right_view(root):
    if root is None:
        return
    queue = deque([root])
    rightmost_val = None
    while queue:
        node = queue.pop()
        if node.right:
            queue.appendleft(node.right)
            rightmost_val = node.right.data
        if node.left:
            queue.appendleft(node.left)
    print(rightmost_val)

def create_tree_from_input(lines):
    root = None
    for line in lines:
        if len(line) > 0:
            values = list(map(int, line.split()))
            nodes = [None] * (len(values) + 1)
            for i, value in enumerate(values):
                nodes[i] = Node(value)
            for i in range(len(values)):
                if nodes[i] is not None:
                    if i < len(values)-1:
                        nodes[i].right = nodes[i+1]
                    else:
                        nodes[i].right = None
                    if i > 0:
                        nodes[i].left = nodes[i-1]
                    else:
                        nodes[i].left = None
                    root = nodes[i]
    return root

def main():
    lines = []
    while True:
        line = input()
        if line == "":
            break
        lines.append(line)
    root = create_tree_from_input(lines)
    right_view(root)

main()

This code creates a binary tree from the input data and then prints the right view of the tree. The right view is the rightmost node in each level of the tree.

The `create_tree_from_input` function creates the binary tree from the given input. It takes a list of lines where each line represents a node and its children, and creates the binary tree.

The `right_view` function prints the right view of the tree. It uses a queue to process the nodes of each level of the tree. The rightmost node in each level is the last node in the queue.

In the `main` function, the program reads the input from the console and uses the `create_tree_from_input` and `right_view` functions to print the right view of the tree.