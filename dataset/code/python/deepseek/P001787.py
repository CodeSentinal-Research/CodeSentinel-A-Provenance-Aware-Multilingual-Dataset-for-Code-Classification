class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert_node(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val < key:
            root.right = insert_node(root.right, key)
        else:
            root.left = insert_node(root.left, key)
    return root

def main():
    n = int(input().strip())
    root = None
    for i in range(n):
        line = input().strip().split()
        root = insert_node(root, int(line[0]))
    key = int(input().strip())
    root = insert_node(root, key)
    print(root.val)

if __name__ == "__main__":
    main()