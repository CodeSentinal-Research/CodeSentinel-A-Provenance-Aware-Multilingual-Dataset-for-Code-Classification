Here is the Python code for constructing a Binary Search Tree from its Preorder Traversal:

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, root, key):
        if root is None:
            return Node(key)
        if key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)
        return root

    def construct(self, keys, start, end):
        if start > end:
            return None
        mid = (start + end) // 2
        root = self.insert(self.root, keys[mid])
        root.left = self.construct(keys, start, mid - 1)
        root.right = self.construct(keys, mid + 1, end)
        return root

def construct_bst():
    n = int(input())
    keys = list(map(int, input().split()))
    bst = BST()
    bst.root = Node(keys[0])
    bst.construct(keys, 0, n - 1)

construct_bst()

This code first reads the number of keys and the preorder traversal of the BST. Then it creates a BST using the preorder traversal and inserts the keys into the BST.

The `construct` function is a recursive function that constructs the BST. It finds the middle element of the keys and the range of indices for the left and right subarrays, and then recursively constructs the left and right subtrees.

The `construct` function starts at the first element and moves to the last element, and for each element, it constructs the left and right subtrees.

The `construct` function also takes a range of indices, and it finds the middle element of this range. It then recursively constructs the left and right subtrees.

In the `construct_bst` function, it reads the number of keys and the preorder traversal of the BST. It creates a BST using the preorder traversal and inserts the keys into the BST.