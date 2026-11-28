class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        closest = root.val
        cur = root

        while cur:
            if abs(cur.val - target) < abs(closest - target) or                (abs(cur.val - target) == abs(closest - target) and cur.val < closest):
                closest = cur.val

            if target < cur.val:
                cur = cur.left
            else:
                cur = cur.right

        return closest