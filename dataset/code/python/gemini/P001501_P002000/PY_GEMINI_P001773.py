from collections import defaultdict
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def antiDiagonalSum(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        d_map = defaultdict(int)

        def dfs(node, d):
            if not node:
                return
            d_map[d] += node.val
            dfs(node.left, d)
            dfs(node.right, d + 1)

        dfs(root, 0)
        return [d_map[k] for k in sorted(d_map.keys())]