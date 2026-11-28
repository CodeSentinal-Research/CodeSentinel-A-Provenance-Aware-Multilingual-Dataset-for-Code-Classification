Here's the Python code for converting a binary tree into a circular doubly linked list. In the code, we use a recursive inorder traversal method which will give us the nodes in the order of inorder traversal (left node, root, right node).

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(data, self.root)

    def _insert(self, data, node):
        if data < node.data:
            if node.left is None:
                node.left = Node(data)
            else:
                self._insert(data, node.left)
        else:
            if node.right is None:
                node.right = Node(data)
            else:
                self._insert(data, node.right)

    def inorder_print(self):
        if self.root is not None:
            self._inorder_print(self.root)

    def _inorder_print(self, node):
        if node.left is not None:
            self._inorder_print(node.left)
        print(node.data)
        if node.right is not None:
            self._inorder_print(node.right)


def convert_to_dll(binary_tree):
    if binary_tree.root is None:
        return None

    if binary_tree.root.left is None and binary_tree.root.right is None:
        return binary_tree.root

    left = convert_to_dll(binary_tree)

    binary_tree.root.left = binary_tree.root.right = None

    node = left
    while node.right:
        node = node.right

    node.right = binary_tree.root
    binary_tree.root.left = node

    return left


def print_dll(head):
    if head is None:
        return

    while True:
        print(head.data)
        node = head
        head = head.right
        if node == head:
            break


def main():
    binary_tree = BinaryTree()

    n = int(input())
    for _ in range(n):
        data = int(input())
        binary_tree.insert(data)

    binary_tree.inorder_print()

    head = convert_to_dll(binary_tree)
    print_dll(head)


if __name__ == "__main__":
    main()
This code will work for the given problem. Please note that the code assumes the input will be a binary tree where each node has a unique value. If the input is not a binary tree, the code may not work correctly.