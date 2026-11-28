Here is the Python code to solve the problem:

def is_subtree(T1, T2):
    if T1 is None:
        return False
    if T1.val == T2.val and is_identical(T1, T2):
        return True
    return is_subtree(T1.left, T2) or is_subtree(T1.right, T2)

def is_identical(T1, T2):
    if T1 is None and T2 is None:
        return True
    if T1 is None or T2 is None:
        return False
    return (T1.val == T2.val) and is_identical(T1.left, T2.left) and is_identical(T1.right, T2.right)

class Node:
    def __init__(self, key):
        self.val = key
        self.left = None
        self.right = None

def string_to_tree(s):
    values = [int(v) for v in s.split()]
    nodes = {i: Node(v) for i, v in enumerate(values)}
    for i, v in enumerate(values):
        if v is not None:
            nodes[i].left = nodes[v]
            nodes[i].right = nodes[v]
    return nodes[next(iter(nodes))]

def main():
    T1_nodes = string_to_tree(input())
    T2_nodes = string_to_tree(input())
    print('YES' if is_subtree(T1_nodes, T2_nodes) else 'NO')

if __name__ == '__main__':
    main()

This code first defines two helper functions, `is_subtree` and `is_identical`, which check if one tree is a subtree of another. `is_subtree` uses a recursive approach to check if the second tree is a subtree of the first. `is_identical` checks if two trees are identical.

The main function reads the two trees from input and prints 'YES' if the second tree is a subtree of the first, otherwise it prints 'NO'.

Please note that the input for the trees is a string representation of their nodes, where each number is a node's value and its children are represented by their indices.