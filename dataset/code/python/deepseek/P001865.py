Here is the Python code for the problem:

class Node:
    def __init__(self, key, freq):
        self.key = key
        self.freq = freq
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, key, freq):
        if self.root is None:
            self.root = Node(key, freq)
        else:
            self._insert(self.root, key, freq)

    def _insert(self, node, key, freq):
        if node.freq > freq:
            if node.left is None:
                node.left = Node(key, freq)
            else:
                self._insert(node.left, key, freq)
        else:
            if node.right is None:
                node.right = Node(key, freq)
            else:
                self._insert(node.right, key, freq)

    def in_order_traversal(self, node, result):
        if node is not None:
            self.in_order_traversal(node.left, result)
            result.append(node.key)
            self.in_order_traversal(node.right, result)

def construct_bst(keys, freqs):
    bst = BST()
    for key, freq in zip(keys, freqs):
        bst.insert(key, freq)
    return bst

def main():
    keys = list(map(int, input().split()))[1:]
    freqs = list(map(int, input().split()))[1:]
    bst = construct_bst(keys, freqs)
    result = []
    bst.in_order_traversal(bst.root, result)
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()

In this code, we first define a Node class which will be used to create new nodes in our BST. Then, we define a BST class which will contain the methods to insert nodes into the BST.

In the construct_bst function, we create an instance of BST and then for each key-freq pair, we insert them into the BST.

In the main function, we read the keys and freqs from the input. We then construct the BST and print out the keys in order, resulting in the constructed BST.