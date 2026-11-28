class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 0

        def depth(node):
            if not node:
                return 0
            l = depth(node.left)
            r = depth(node.right)
            self.ans = max(self.ans, l + r)
            return 1 + max(l, r)

        depth(root)
        return self.ans