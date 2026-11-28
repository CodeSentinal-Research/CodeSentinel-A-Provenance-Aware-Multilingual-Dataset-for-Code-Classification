Here is the Python code for the problem:

from queue import Queue

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def isPerfect(root, level=0):
    if root is None:
        return True

    if root.left is None and root.right is None:
        return True if level == 0 else False

    if root.left is None or root.right is None:
        return False

    return (isPerfect(root.left, level+1) and
            isPerfect(root.right, level+1))

def build_tree(lines):
    root = None
    nodes = []

    for line in lines:
        values = list(map(int, line.split()))
        node = Node(values[0])
        nodes.append(node)

        if values[1] != -1:
            node.left = nodes[values[1]]

        if values[2] != -1:
            node.right = nodes[values[2]]

        if root is None:
            root = node

    return root

def main():
    n = int(input())
    lines = [input() for _ in range(n)]
    root = build_tree(lines)

    if isPerfect(root):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
This code first reads the number of nodes and the data of each node from the standard input. Then it builds the tree based on the data. Finally, it uses the `isPerfect` function to check if the tree is perfect, and prints the result.