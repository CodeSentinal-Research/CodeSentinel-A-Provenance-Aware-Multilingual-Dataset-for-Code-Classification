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
            row_max = float('-inf')
            for _ in range(len(dq)):
                node = dq.popleft()
                row_max = max(row_max, node.val)
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            res.append(row_max)

        return res