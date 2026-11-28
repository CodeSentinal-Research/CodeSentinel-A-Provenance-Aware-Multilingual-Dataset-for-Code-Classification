Here is the Python code for the problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def min_value_node(node):
    current = node
    while(current.left is not None):
        current = current.left
    return current


def delete_node(root, key):
    if root is None:
        return root
    if key < root.data:
        root.left = delete_node(root.left, key)
    elif(key > root.data):
        root.right = delete_node(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        temp = min_value_node(root.right)
        root.data = temp.data
        root.right = delete_node(root.right, temp.data)
    return root


def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root


def pre_order(root):
    if root:
        print(root.data),
        pre_order(root.left)
        pre_order(root.right)


def main():
    root = None
    keys = [4, 2, 5, 1, 3]
    for key in keys:
        root = insert(root, key)
    print("Binary Search Tree after deletion of nodes is:")
    pre_order(root)


main()

In this code, the function `insert` is used to add nodes to the Binary Search Tree. The function `delete_node` is used to delete a key from the Binary Search Tree. If the key to be deleted is less than the root, it goes to the left child of the root. If the key to be deleted is greater than the root, it goes to the right child of the root. If the key is less than and greater than the root, we find the leftmost node in the right subtree and delete it.

In the main function, we first create a binary search tree using the keys. Then, we print the pre-order traversal of the binary search tree after each deletion of a key.