class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def ceilBST(self, root: TreeNode, key: int) -> int:
        ceil_val = -1
        cur = root

        while cur:
            if cur.val == key:
                return cur.val
            elif cur.val > key:
                ceil_val = cur.val
                cur = cur.left
            else:
                cur = cur.right

        return ceil_val