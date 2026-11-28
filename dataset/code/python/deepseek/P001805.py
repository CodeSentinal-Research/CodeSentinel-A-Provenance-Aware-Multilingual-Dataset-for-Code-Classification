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

def count(root):
    if root is None:
        return 0
    else:
        return 1 + count(root.left) + count(root.right)

def median(root):
    total_nodes = count(root)
    if total_nodes % 2 == 0:
        left_nodes = count(root, left=True)
        right_nodes = count(root, right=True)
        return (left_nodes + right_nodes) / 2
    else:
        return count(root, right=True)

def count(root, left=False, right=False):
    if root is None:
        return 0
    elif left:
        return 1 + count(root.left, left=True)
    elif right:
        return 1 + count(root.right, right=True)
    else:
        return count(root.left) + count(root.right)

def main():
    n = int(input().strip())
    root = None
    for i in range(n):
        data = int(input().strip())
        root = insert(root, data)
    print(median(root))

if __name__ == "__main__":
    main()