from collections import deque
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findLevelMedians(self, root: TreeNode) -> List[float]:
        if not root:
            return []
        dq = deque([root])
        medians = []

        while dq:
            size = len(dq)
            vals = []
            for _ in range(size):
                node = dq.popleft()
                vals.append(node.val)
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            vals.sort()
            # If current bit is set, multiply base into result
            if size % 2 == 1:
                medians.append(float(vals[size // 2]))
            else:
                medians.append((vals[size // 2 - 1] + vals[size // 2]) / 2.0)

        return medians