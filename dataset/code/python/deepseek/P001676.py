from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert_node(data, root):
    if root is None:
        return Node(data)
    else:
        if root.data < data:
            root.right = insert_node(data, root.right)
        else:
            root.left = insert_node(data, root.left)
    return root

def anti_diagonal_traversal(root):
    if root is None:
        return

    q = deque()
    q.append((root, 0))

    while q:
        node, diag = q.popleft()

        if node:
            print(f'Diagonal from left to right: {node.data}', end=' ')
            q.append((node.left, diag + 1))
            q.append((node.right, diag))
        else:
            print('')

def main():
    root = None

    n = int(input())
    for i in range(n):
        data = int(input())
        root = insert_node(data, root)

    anti_diagonal_traversal(root)

if __name__ == "__main__":
    main()