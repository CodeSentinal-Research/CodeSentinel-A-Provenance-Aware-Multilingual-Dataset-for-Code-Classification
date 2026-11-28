class TreeNode:
    def __init__(self, val=0, left=None, right=None, isThreaded=False):
        self.val = val
        self.left = left
        self.right = right
        self.isThreaded = isThreaded

class Solution:
    def convertToThreaded(self, root: TreeNode) -> TreeNode:
        prev = None

        def inorder(node):
            nonlocal prev
            if not node:
                return
            inorder(node.left)
            if prev and not prev.right:
                prev.right = node
                prev.isThreaded = True
            prev = node
            inorder(node.right)

        inorder(root)
        return root