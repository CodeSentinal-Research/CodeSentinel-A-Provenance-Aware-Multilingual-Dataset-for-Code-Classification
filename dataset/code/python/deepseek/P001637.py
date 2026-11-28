Here is a Python solution for the problem:

def countLeafNodes(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return 1
    else:
        return countLeafNodes(root.left) + countLeafNodes(root.right)

In this code, we define a function countLeafNodes that takes the root of a binary tree as input. If the root is None, we return 0. If the root is a leaf node (i.e., both left and right children are None), we return 1. Otherwise, we return the sum of the counts of the left and right subtrees.

Here is the Python code for the main function:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree(lines):
    nodes = []
    for line in lines:
        if line == '-1':
            nodes.append(None)
        else:
            nodes.append(Node(line))
    for i in range(len(nodes)):
        if nodes[i]:
            if i*2+1<len(nodes):
                nodes[i].left = nodes[i*2+1]
            if i*2+2<len(nodes):
                nodes[i].right = nodes[i*2+2]
    return nodes[0]

def main():
    n = int(input())
    lines = list(map(int,input().split()))
    root = build_tree(lines[:n])
    print(countLeafNodes(root))

if __name__ == "__main__":
    main()

In this code, we first input the number of nodes in the tree (n), followed by the data of the nodes. We then build the tree and print the count of leaf nodes.