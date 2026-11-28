from collections import deque
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []
        dq = deque([root])
        res = []

        while dq:
            size = len(dq)
            level_sum = 0
            for _ in range(size):
                node = dq.popleft()
                level_sum += node.val
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            res.append(level_sum / size)

        return res