Here is the Python code:

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def min_subtree_sum(node):
    if node is None:
        return 0
    return node.val + min(min_subtree_sum(node.left), min_subtree_sum(node.right))

def solve(node):
    if node is None:
        return 0
    total = node.val + min_subtree_sum(node.left) + min_subtree_sum(node.right)
    return total

def build_tree(nodes):
    if len(nodes) == 0:
        return None
    val = nodes.pop(0)
    node = Node(val)
    node.left = build_tree(nodes)
    node.right = build_tree(nodes)
    return node

def main():
    N = int(input().strip())
    nodes = list(map(int, input().strip().split()))
    nodes.insert(0, None)
    tree = build_tree(nodes)
    print(solve(tree))

if __name__ == "__main__":
    main()

This code first defines a `Node` class for the binary tree nodes. Then, it defines the `min_subtree_sum` function, which calculates the sum of the node values in the minimum subtree. The `solve` function calculates the total sum of the node values in the entire tree. The `build_tree` function builds the binary tree from the given node values. The `main` function reads the tree from standard input and prints the total sum of the node values in the minimum subtree.