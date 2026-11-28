Here is a Python code that solves the problem. This code defines a class `Node` for each node in the Binary Search Tree and a class `BST` for the entire tree. The `search` method of the `BST` class traverses the tree in order (left, node, right) and checks if the current node's data equals the target key. If it does, the method returns `True`. Otherwise, it recursively checks the left and right subtrees. If the key is not found in the tree, the method returns `False`.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
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

    def search(self, key):
        if self.root is not None:
            res = self._search(key, self.root)
            if res:
                return "YES"
            else:
                return "NO"
        else:
            return "NO"

    def _search(self, key, node):
        if node is None:
            return False
        elif node.data == key:
            return True
        elif key < node.data:
            return self._search(key, node.left)
        else:
            return self._search(key, node.right)

def main():
    bst = BST()
    n = int(input().strip())
    for i in range(n):
        bst.insert(int(input().strip()))
    key = int(input().strip())
    print(bst.search(key))

if __name__ == "__main__":
    main()

In this code, the `main` function reads the number of nodes (`n`), the nodes data (`data`), and the key (`key`) from the input. It then creates a Binary Search Tree (`bst`), inserts the nodes, and finally searches for the key and prints the result.