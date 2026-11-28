class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def smallestGreater(self, root: TreeNode, key: int) -> int:
        ans = -1
        cur = root

        while cur:
            if cur.val > key:
                ans = cur.val
                cur = cur.left
            else:
                cur = cur.right

        return ans