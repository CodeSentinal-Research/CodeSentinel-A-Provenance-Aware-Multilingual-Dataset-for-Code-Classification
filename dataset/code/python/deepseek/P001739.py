Here is a Python solution using a recursive approach:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def remove_leaf_nodes(root):
    if root is None:
        return None
    root.left = remove_leaf_nodes(root.left)
    root.right = remove_leaf_nodes(root.right)
    if root.left is None and root.right is None:
        return None
    return root

def create_tree(lines):
    if lines[0] == 'N':
        return None
    node = Node(int(lines[0]))
    node.left = create_tree(lines[1:])
    node.right = create_tree(lines[1:])
    return node

def print_tree(root):
    if root is None:
        return
    print(root.val, end=' ')
    print_tree(root.left)
    print_tree(root.right)

def main():
    lines = input().split()
    N = int(lines[0])
    lines = lines[1:]
    tree = create_tree(lines)
    new_tree = remove_leaf_nodes(tree)
    print_tree(new_tree)

if __name__ == "__main__":
    main()

In this code, we first define a `Node` class for the nodes of the binary tree. Then, we define two functions: `remove_leaf_nodes` and `create_tree`. `remove_leaf_nodes` is a recursive function that traverses the tree and deletes the leaf nodes. `create_tree` is a function that creates a binary tree from the given input. Finally, we define the `main` function that reads the input and processes the tree.