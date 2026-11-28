Here is the Python code for the problem:

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.key < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

def find_key_with_rank(root, rank):
    count_left = count_nodes(root.left)
    if count_left == rank:
        return root.key
    elif count_left < rank:
        return find_key_with_rank(root.right, rank - count_left - 1)
    else:
        return find_key_with_rank(root.left, rank)

def count_nodes(root):
    if root is None:
        return 0
    else:
        return 1 + count_nodes(root.left) + count_nodes(root.right)

def main():
    N = int(input().strip())
    keys = list(map(int, [input() for _ in range(N)]))
    root = None
    for key in keys:
        root = insert(root, key)
    R = int(input().strip())
    print(find_key_with_rank(root, R))

if __name__ == "__main__":
    main()

This code first reads the number of nodes and the keys for the BST from the input. Then, it constructs the BST by inserting the keys into the BST. Finally, it reads the rank and prints the key with the given rank.