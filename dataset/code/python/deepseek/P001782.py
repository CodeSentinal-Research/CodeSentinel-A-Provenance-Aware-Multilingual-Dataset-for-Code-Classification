Here is the Python code for the problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree(nodes):
    if nodes[0] is None:
        return None

    node = Node(nodes.pop(0))
    node.left = build_tree(nodes)
    node.right = build_tree(nodes)
    return node

def max_symmetric_subtree(root):
    if root is None:
        return 0

    left_height = max_symmetric_subtree(root.left)
    right_height = max_symmetric_subtree(root.right)

    return max(left_height, right_height) + 1

def main():
    N = int(input().strip())
    nodes = list(map(int, input().strip().split()))
    root = build_tree(nodes)
    print(max_symmetric_subtree(root))

if __name__ == '__main__':
    main()

In this code, a binary tree is first created from the input. The `build_tree` function is a recursive function that builds a binary tree from a list of integers. It creates a node for each integer in the list, and recursively builds the left and right subtrees. The `max_symmetric_subtree` function is a helper function that finds the maximum height of a symmetric subtree.

In the `main` function, it first reads the number of nodes in the tree and the nodes themselves. It then creates the tree and prints the size of the largest symmetric subtree.