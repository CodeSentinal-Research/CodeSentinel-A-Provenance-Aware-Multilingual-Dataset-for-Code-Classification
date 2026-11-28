class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderPredecessor(self, root: TreeNode, p: TreeNode) -> TreeNode:
        pred = None
        cur = root
        while cur:
            if cur.val < p.val:
                pred = cur
                cur = cur.right
            else:
                cur = cur.left
        return pred