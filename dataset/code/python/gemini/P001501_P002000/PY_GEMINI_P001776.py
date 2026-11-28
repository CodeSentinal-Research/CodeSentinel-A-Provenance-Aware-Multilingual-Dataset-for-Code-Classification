from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isEveryLevelPalindromic(self, root: TreeNode) -> bool:
        if not root:
            return True
        dq = deque([root])

        while dq:
            size = len(dq)
            vals = []
            for _ in range(size):
                node = dq.popleft()
                vals.append(node.val)
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            if vals != vals[::-1]:
                return False

        return True