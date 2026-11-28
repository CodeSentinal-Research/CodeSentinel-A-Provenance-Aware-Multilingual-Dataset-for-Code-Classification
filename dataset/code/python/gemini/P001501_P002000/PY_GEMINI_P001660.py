from collections import defaultdict
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        trees = defaultdict(int)
        res = []

        def serialize(node):
            if not node:
                return '#'
            serial = f"{node.val},{serialize(node.left)},{serialize(node.right)}"
            trees[serial] += 1
            if trees[serial] == 2:
                res.append(node)
            return serial

        serialize(root)
        return res