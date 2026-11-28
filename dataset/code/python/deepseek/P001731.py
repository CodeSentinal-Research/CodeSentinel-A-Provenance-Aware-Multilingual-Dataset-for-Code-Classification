Here is a Python solution for the given problem.

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class ThreadedBinaryTree:
    def __init__(self):
        self.firstNode = None

    def flatten(self, root):
        if root is None:
            return

        self.flatten(root.left)

        root.right = self.firstNode
        root.left = None
        self.firstNode = root

        self.flatten(root.right)

    def construct(self, nodes_list):
        if not nodes_list:
            return None

        index = 0
        if nodes_list[index] == 'X'::
            return None

        root = Node(nodes_list[index])
        index += 1
        root.left = self.construct(nodes_list)
        index = self.construct(nodes_list)
        root.right = self.construct(nodes_list)

        return root

    def solve(self, nodes_list):
        self.firstNode = None
        root = self.construct(nodes_list)
        self.flatten(root)

        return self.firstNode

if __name__ == "__main__":
    n = int(input())
    nodes_list = input().split()
    tbt = ThreadedBinaryTree()
    first_node = tbt.solve(nodes_list)

    current_node = first_node
    while current_node:
        print(current_node.val, end=' ')
        current_node = current_node.right
        if current_node is not None:
            print('X', end=' ')
        else:
            print()

This code first reads the number of nodes and the node values from the input. It then constructs the binary tree using the given node values. After constructing the binary tree, it flattens the tree into a threaded binary tree. Finally, it prints the threaded binary tree.

Please note that this code assumes that the input format is correct and the tree is well-formed. You may need to adjust the input and handling based on the actual requirements of your problem.