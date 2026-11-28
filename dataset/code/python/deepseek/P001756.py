Here is the Python code for your problem:

class Node:
    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

def solve(N, tree):
    if not tree:
        return

    stack = [(tree, False)]

    while stack:
        node, leaf = stack.pop()
        if leaf:
            if not node.left and not node.right:
                return "NO"
        else:
            if node.left and node.right:
                stack.append((node.left, True))
                stack.append((node.right, True))

    return "YES"

def main():
    N = int(input().strip())
    tree = Node()
    nodes = [input().strip().split() for _ in range(N)]
    tree_list = [None if i == '-' else Node() for i in nodes]

    for i in range(N):
        left, right = nodes[i]
        if left != '-':
            tree_list[i].left = tree_list[int(left)]
        if right != '-':
            tree_list[i].right = tree_list[int(right)]

    tree = tree_list[0]
    print(solve(N, tree))

if __name__ == "__main__":
    main()

This program reads the input and constructs a binary tree from it. The `solve` function checks if every leaf node has a sibling in the binary tree. If all leaf nodes have siblings, it returns "YES". Otherwise, it returns "NO". The `main` function reads the input, constructs the binary tree, and prints the result of the `solve` function.