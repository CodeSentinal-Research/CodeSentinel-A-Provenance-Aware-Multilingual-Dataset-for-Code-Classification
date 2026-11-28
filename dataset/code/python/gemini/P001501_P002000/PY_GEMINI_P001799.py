class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        stack = []
        cur = root

        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.right
            cur = stack.pop()
            k -= 1
            if k == 0:
                return cur.val
            cur = cur.left

        return -1