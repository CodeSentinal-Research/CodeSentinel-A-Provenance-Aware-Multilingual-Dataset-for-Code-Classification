from collections import deque
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        dq = deque([root])
        res = []

        while dq:
            size = len(dq)
            max_val = float('-inf')
            for _ in range(size):
                node = dq.popleft()
                max_val = max(max_val, node.val)
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            res.append(max_val)

        return res