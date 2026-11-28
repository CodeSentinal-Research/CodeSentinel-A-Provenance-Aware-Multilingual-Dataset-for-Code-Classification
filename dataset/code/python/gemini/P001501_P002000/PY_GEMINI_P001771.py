from collections import defaultdict
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def verticalSum(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        v_map = defaultdict(int)

        def dfs(node, col):
            if not node:
                return
            v_map[col] += node.val
            dfs(node.left, col - 1)
            dfs(node.right, col + 1)

        dfs(root, 0)
        return [v_map[k] for k in sorted(v_map.keys())]