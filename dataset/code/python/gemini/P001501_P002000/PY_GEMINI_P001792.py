class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> TreeNode:
        succ = None
        cur = root
        while cur:
            if cur.val > p.val:
                succ = cur
                cur = cur.left
            else:
                cur = cur.right
        return succ