Here is the Python code for the problem:

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def solve(node, visited):
    if node is None:
        return 0
    if node.value in visited:
        return visited[node.value]
    visited[node.value] = solve(node.right, visited) + solve(node.left, visited) + node.value
    return visited[node.value]

def transform(node):
    visited = {}
    solve(node, visited)
    max_value = max(visited.keys())
    node.value = max_value
    for key in visited:
        if key < max_value:
            visited[key] = max_value
    return node

def print_tree(node):
    if node is None:
        return
    print_tree(node.right)
    print(node.value)
    print_tree(node.left)

def input_tree():
    n = int(input().strip())
    nodes = [None] * (n + 1)
    for i in range(n):
        line = input().strip().split()
        parent = int(line[0])
        if parent != -1:
            nodes[parent] = Node(nodes[parent])
            if line[1] != -1:
                nodes[parent].left = Node(int(line[1]))
            if line[2] != -1:
                nodes[parent].right = Node(int(line[2]))
    return nodes[1]

def main():
    node = input_tree()
    transformed_node = transform(node)
    print_tree(transformed_node)

main()

This code reads the input for the binary search tree, transforms the tree by replacing each node's value with the sum of all keys greater than or equal to that node, and then prints the transformed tree.

The `input_tree` function reads the input for the binary search tree. The `main` function reads the input, transforms the tree, and then prints the transformed tree.

Note: This code assumes that the input follows the format specified in the problem.