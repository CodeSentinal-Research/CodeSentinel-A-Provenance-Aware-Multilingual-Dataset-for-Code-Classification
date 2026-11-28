class TreeNode:
    def __init__(self, val=0, left=None, right=None, isThreaded=False):
        self.val = val
        self.left = left
        self.right = right
        self.isThreaded = isThreaded

class Solution:
    def verifyThreaded(self, root: TreeNode) -> bool:
        if not root:
            return True
        cur = root
        while cur.left:
            cur = cur.left

        visited = 0
        while cur:
            visited += 1
            if cur.isThreaded:
                cur = cur.right
            else:
                cur = cur.right
                while cur and cur.left:
                    cur = cur.left

        return visited > 0