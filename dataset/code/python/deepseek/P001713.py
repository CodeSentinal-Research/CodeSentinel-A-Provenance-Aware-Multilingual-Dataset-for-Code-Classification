Here is the Python code:

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def removeHalfNodes(root, parent=None):
    if root is None:
        return

    left_is_half_node = removeHalfNodes(root.left, root)
    right_is_half_node = removeHalfNodes(root.right, root)

    if left_is_half_node and right_is_half_node:
        if parent is not None:
            if parent.left == root:
                parent.left = None
            else:
                parent.right = None
        root = None

    return left_is_half_node or right_is_half_node

def printTree(node, indent=0, left=True):
    if node is None:
        return

    printTree(node.right, indent+1, False)

    for i in range(indent):
        print('    ', end='')

    if left:
        print('┌──', end='')
    else:
        print('┐──', end='')

    print(node.val)

    printTree(node.left, indent+1, True)

def createTree(lines):
    nodes = {}
    for line in lines:
        val = line[0]
        nodes[val] = Node(val)
        if line[1] != -1:
            nodes[val].left = nodes[line[1]]
        if line[2] != -1:
            nodes[val].right = nodes[line[2]]
    return nodes[lines[0][0]]

def main():
    n = int(input().strip())
    lines = []
    for i in range(n):
        line = input().strip().split()
        lines.append(line)
    root = createTree(lines)
    removeHalfNodes(root)
    printTree(root)

main()

This Python code defines a `Node` class, a `removeHalfNodes` function, a `printTree` function, and a `createTree` function. The `removeHalfNodes` function recursively checks each node and if it is a half node, it is removed from the tree by setting its parent's child to `None`. The `printTree` function uses a depth-first traversal to print the tree. The `createTree` function is used to create the binary tree from the input lines. The `main` function handles the input and output.