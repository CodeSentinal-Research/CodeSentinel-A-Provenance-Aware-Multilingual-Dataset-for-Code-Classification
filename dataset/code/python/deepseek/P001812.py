class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.key = key

def insert(node, key):
    if node is None:
        return Node(key)
    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)
    return node

def print_keys_in_range(node, l, r):
    if node is None:
        return
    if l < node.key and node.key <= r:
        print(node.key, end=' ')
    if l < node.key:
        print_keys_in_range(node.left, l, r)
    if node.key <= r:
        print_keys_in_range(node.right, l, r)

def main():
    n = int(input().strip())
    keys = list(map(int, input().strip().split()))
    l, r = map(int, input().strip().split())
    root = None
    for key in keys:
        root = insert(root, key)
    print_keys_in_range(root, l, r)

if __name__ == "__main__":
    main()

In this code, we first define a Node class to represent each node in the BST. The insert function is used to insert a new key into the BST. The print_keys_in_range function is used to print all keys within the inclusive range [L, R] in sorted order. The main function reads the BST and range, constructs the BST, and then calls print_keys_in_range to print the keys within the range.