Sure, here is a Python solution for the problem using binary search. The main function reads the input and finds the closest key.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.data < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

def find_closest_key(root, target):
    current = root
    closest = root.data

    while current:
        if abs(current.data - target) < abs(closest - target):
            closest = current.data

        if target > current.data:
            current = current.right
        else:
            current = current.left

    return closest

def main():
    n = int(input().strip())
    root = None

    for i in range(n):
        key = int(input().strip())
        root = insert(root, key)

    target = int(input().strip())
    print(find_closest_key(root, target))

if __name__ == "__main__":
    main()

This program reads the input and creates a binary search tree. It then reads a target value and prints the closest key to the target value in the binary search tree.