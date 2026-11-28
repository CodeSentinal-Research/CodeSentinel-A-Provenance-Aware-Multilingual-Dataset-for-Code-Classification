from collections import deque
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def smallestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        dq = deque([root])
        res = []

        while dq:
            size = len(dq)
            min_val = float('inf')
            for _ in range(size):
                node = dq.popleft()
                min_val = min(min_val, node.val)
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            res.append(min_val)

        return res