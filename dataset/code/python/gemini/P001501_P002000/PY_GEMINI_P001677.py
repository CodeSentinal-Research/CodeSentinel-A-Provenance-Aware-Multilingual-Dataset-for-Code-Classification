from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findCousins(self, root: TreeNode, target_val: int) -> list:
        if not root or root.val == target_val:
            return []
        dq = deque([root])
        found = False

        while dq and not found:
            size = len(dq)
            for _ in range(size):
                curr = dq.popleft()
                if (curr.left and curr.left.val == target_val) or (curr.right and curr.right.val == target_val):
                    found = True
                else:
                    if curr.left: dq.append(curr.left)
                    if curr.right: dq.append(curr.right)

        return [n.val for n in dq] if found else []