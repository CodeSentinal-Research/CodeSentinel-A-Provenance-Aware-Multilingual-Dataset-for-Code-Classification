class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.key = key

def insert(node, key):
    if node is None:
        return Node(key)
    else:
        if node.key < key:
            node.right = insert(node.right, key)
        else:
            node.left = insert(node.left, key)
    return node

def find_smallest_greater(node, x):
    current = node
    while current.left is not None:
        if current.left.key > x:
            return current.left.key
        else:
            current = current.left
    return None

def main():
    n = int(input().strip())
    root = None
    for _ in range(n):
        line = input().strip().split()
        key = int(line[0])
        root = insert(root, key)
    x = int(input().strip())
    result = find_smallest_greater(root, x)
    print(result if result is not None else 'None')

if __name__ == '__main__':
    main()