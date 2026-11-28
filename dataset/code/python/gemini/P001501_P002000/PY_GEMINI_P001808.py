class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def joinBST(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        if not root1:
            return root2
        if not root2:
            return root1

        def insert(node, val):
            if not node:
                return TreeNode(val)
            if val < node.val:
                node.left = insert(node.left, val)
            else:
                node.right = insert(node.right, val)
            return node

        def add_all(node):
            if not node:
                return
            insert(root1, node.val)
            add_all(node.left)
            add_all(node.right)

        add_all(root2)
        return root1