Here is a Python solution with a main function and input handling. This solution uses a recursive approach to check each node in the binary tree. The `is_good` function is called for each node and if it returns `True`, the node is counted as good. Otherwise, the node is not counted.

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def is_good(node, max_value):
    if node is None:
        return True
    if node.value >= max_value:
        return False
    max_value = max(max_value, node.value)
    return is_good(node.left, max_value) and is_good(node.right, max_value)

def count_good_nodes(root):
    if root is None:
        return 0
    return is_good(root, float('-inf'))

def main():
    N = int(input().strip())
    nodes = [int(x) for x in input().strip().split()]
    index = 0
    root = None
    nodes_dict = {}
    for value in nodes:
        node = Node(value)
        nodes_dict[value] = node
        if root is None:
            root = node
        if nodes[index - 1] in nodes_dict:
            nodes_dict[nodes[index - 1]].left = node
        else:
            root.left = node
        index += 1
    for value in nodes:
        if nodes[index - 1] in nodes_dict:
            nodes_dict[nodes[index - 1]].right = nodes_dict[value]
        else:
            root.right = nodes_dict[value]
        index += 1
    print(count_good_nodes(root))

if __name__ == "__main__":
    main()

This code reads the number of nodes N and the node values, then constructs the binary tree from these values. The `is_good` function checks if a node is good by recursively checking each node and ensuring the node's value is not greater than any ancestor's value.

The `count_good_nodes` function calls the `is_good` function on the root of the tree and returns the count.

The `main` function reads the tree from the input, constructs the tree, and prints the count of good nodes.