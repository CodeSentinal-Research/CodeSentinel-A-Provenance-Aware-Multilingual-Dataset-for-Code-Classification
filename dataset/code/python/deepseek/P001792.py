class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert(key, self.root)

    def _insert(self, key, node):
        if key < node.key:
            if node.left is None:
                node.left = Node(key)
            else:
                self._insert(key, node.left)
        else:
            if node.right is None:
                node.right = Node(key)
            else:
                self._insert(key, node.right)

    def inorder_successor(self, node):
        if node.right:
            node = node.right
            while node.left:
                node = node.left
            return node
        else:
            parent = node.parent
            while parent and node == parent.right:
                node = parent
                parent = parent.parent
            return parent

    def find(self, key):
        if self.root:
            res = self._find(key, self.root)
            if res:
                return res.key
            else:
                return None
        else:
            return None

    def _find(self, key, node):
        if node is None:
            return None
        if key == node.key:
            return node
        elif key < node.key:
            return self._find(key, node.left)
        else:
            return self._find(key, node.right)

def main():
    tree = BST()
    nodes = [int(node) for node in input().split()][1:]
    for node in nodes:
        tree.insert(node)
    target = int(input().strip())
    print(tree.inorder_successor(tree.find(target)).key if tree.find(target) else None)

if __name__ == "__main__":
    main()