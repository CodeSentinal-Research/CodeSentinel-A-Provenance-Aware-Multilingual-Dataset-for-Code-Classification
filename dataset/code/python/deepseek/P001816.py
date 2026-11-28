Here is the Python code for the problem:

def find_floor(root, key):
    floor = -1
    while root:
        if root.value == key:
            floor = root.value
        elif root.value < key:
            floor = root.value
            root = root.right
        else:
            root = root.left
    return floor

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def build_tree(lines):
    root = None
    for line in lines:
        values = list(map(int, line.split(' ')))
        root = insert_node(root, values[0])
        for value in values[1:-1]:
            insert_node(root, value)
    return root

def insert_node(root, value):
    if root is None:
        return TreeNode(value)
    if value < root.value:
        if root.left is None:
            root.left = TreeNode(value)
        else:
            insert_node(root.left, value)
    else:
        if root.right is None:
            root.right = TreeNode(value)
        else:
            insert.node(root.right, value)
    return root

def main():
    N = int(input().strip())
    lines = [input() for _ in range(N)]
    X = int(input().strip())
    root = build_tree(lines)
    print(find_floor(root, X))

if __name__ == "__main__":
    main()

This code first defines a `TreeNode` class to represent a node in the BST. It also has a `build_tree` function to construct the BST from a list of values. The `insert_node` function is used to insert a new node into the BST. The `find_floor` function is used to find the largest key in the BST that is less than or equal to a given key.

In the `main` function, it reads the number of nodes and the values of the nodes from the input. It then constructs the BST, and finally finds and prints the floor of the given key.