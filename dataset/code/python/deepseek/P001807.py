Here is the Python code for the problem:

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.key = key

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

def print_bst(root):
    if root is not None:
        print_bst(root.left)
        print(root.key)
        print_bst(root.right)

def split_bst(root, x):
    less_than_x = []
    greater_than_x = []
    less_than_x_root = None
    greater_than_x_root = None

    while root:
        if root.key > x:
            if greater_than_x_root is None:
                greater_than_x_root = root
            greater_than_x.append(root)
            root = root.right
        else:
            if less_than_x_root is None:
                less_than_x_root = root
            less_than_x.append(root)
            root = root.left

    for node in less_than_x:
        node.left = None
    for node in greater_than_x:
        node.right = None

    return less_than_x_root, greater_than_x_root

def main():
    n = int(input().strip())
    keys = list(map(int, [input() for _ in range(n)]))
    x = int(input().strip())

    root = None
    for key in keys:
        root = insert(root, key)

    less_than_x, greater_than_x = split_bst(root, x)

    print("Less than x:")
    print_bst(less_than_x)

    print("Greater than x:")
    print_bst(greater_than_x)

if __name__ == "__main__":
    main()

This code first reads the number of keys and the keys themselves. It then constructs the BST and splits it by the given key.