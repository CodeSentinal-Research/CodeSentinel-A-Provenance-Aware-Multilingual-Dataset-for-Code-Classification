class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def floorBST(self, root: TreeNode, key: int) -> int:
        floor_val = -1
        cur = root

        while cur:
            if cur.val == key:
                return cur.val
            elif cur.val < key:
                floor_val = cur.val
                cur = cur.right
            else:
                cur = cur.left

        return floor_val