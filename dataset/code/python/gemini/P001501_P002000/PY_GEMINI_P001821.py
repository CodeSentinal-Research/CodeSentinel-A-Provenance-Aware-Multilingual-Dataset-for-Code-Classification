class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def convertToMinHeap(self, root: TreeNode) -> TreeNode:
        vals = []

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            vals.append(node.val)
            inorder(node.right)

        inorder(root)
        idx = 0

        def preorder(node):
            nonlocal idx
            if not node:
                return
            node.val = vals[idx]
            idx += 1
            preorder(node.left)
            preorder(node.right)

        preorder(root)
        return root