class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, data):
    if root is None:
        return Node(data)
    else:
        if root.data < data:
            root.right = insert(root.right, data)
        else:
            root.left = insert(root.left, data)
    return root

def max_value(root):
    if root is None:
        return None

    max_val = root.data
    while root.right is not None:
        max_val = root.right.data
        root = root.right

    return max_val

def main():
    N = int(input())
    root = None

    for i in range(N):
        data = int(input())
        root = insert(root, data)

    max_val = max_value(root)
    print(max_val)

if __name__ == "__main__":
    main()