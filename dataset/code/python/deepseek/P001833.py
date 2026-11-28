class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def solve(root, dead_ends=0):
    if root is None:
        return dead_ends
    if root.left is None and root.right is None:
        dead_ends += 1
    dead_ends = solve(root.left, dead_ends)
    dead_ends = solve(root.right, dead_ends)
    return dead_ends

def main():
    N = int(input().strip())
    nodes = [input().strip().split() for _ in range(N)]
    nodes = [[int(val) for val in sublist] for sublist in nodes]
    nodes = [Node(val) if len(sublist) == 2 else [None, None] for sublist in nodes]
    root = Node(nodes[0][0])
    root.left = Node(nodes[1][0]) if nodes[1][0] is not None else None
    root.right = Node(nodes[2][0]) if nodes[2][0] is not None else None
    root.left.left = Node(nodes[3][0]) if nodes[3][0] is not None else None
    root.left.right = Node(nodes[4][0]) if nodes[4][0] is not None else None
    root.right.left = Node(nodes[5][0]) if nodes[5][0] is not None else None
    root.right.right = Node(nodes[6][0]) if nodes[6][0] is not None else None
    print(solve(root))

main()

This Python code reads a binary search tree (BST) from the input and counts the number of dead-end nodes. A dead end node is a node that is both a leaf node and has no children. The `solve` function works by recursively checking each node in the BST. If the current node is a dead end, it increments the dead end count.

The `main` function is the entry point of the program. It reads the number of nodes and the values of the nodes from the input, creates the BST, and then calls the `solve` function to count the dead ends.