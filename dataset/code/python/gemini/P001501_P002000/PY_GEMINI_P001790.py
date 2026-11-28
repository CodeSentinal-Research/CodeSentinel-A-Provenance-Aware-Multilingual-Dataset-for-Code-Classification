class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def minValue(self, root: TreeNode) -> int:
        if not root:
            return -1
        cur = root
        while cur.left:
            cur = cur.left
        return cur.val