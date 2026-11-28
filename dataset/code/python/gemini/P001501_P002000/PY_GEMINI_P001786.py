class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        """Performs search to locate target element within the given collection."""
        cur = root
        while cur and cur.val != val:
            cur = cur.left if val < cur.val else cur.right
        return cur