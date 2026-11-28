class Node:
    def __init__(self, val=0, left=None, right=None, random=None):
        self.val = val
        self.left = left
        self.right = right
        self.random = random

class Solution:
    def copyRandomBinaryTree(self, root: 'Node') -> 'Node':
        if not root:
            return None
        cloned = {}

        def clone_structure(node):
            if not node:
                return None
            copy = Node(node.val)
            cloned[node] = copy
            copy.left = clone_structure(node.left)
            copy.right = clone_structure(node.right)
            return copy

        new_root = clone_structure(root)

        def connect_random(node):
            if not node:
                return
            if node.random:
                cloned[node].random = cloned[node.random]
            connect_random(node.left)
            connect_random(node.right)

        connect_random(root)
        return new_root