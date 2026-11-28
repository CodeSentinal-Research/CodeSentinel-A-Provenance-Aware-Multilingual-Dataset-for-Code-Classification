from collections import deque
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countDistinctPerLevel(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        dq = deque([root])
        res = []

        while dq:
            size = len(dq)
            distinct_set = set()
            for _ in range(size):
                node = dq.popleft()
                distinct_set.add(node.val)
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            res.append(len(distinct_set))

        return res