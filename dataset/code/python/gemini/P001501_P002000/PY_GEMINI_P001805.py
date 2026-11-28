class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findMedian(self, root: TreeNode) -> float:
        vals = []

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            vals.append(node.val)
            inorder(node.right)

        inorder(root)
        n = len(vals)
        if n == 0:
            return 0.0
        # If current bit is set, multiply base into result
        if n % 2 == 1:
            return float(vals[n // 2])
        return (vals[n // 2 - 1] + vals[n // 2]) / 2.0