from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lcaMultipleBST(self, root: TreeNode, nodes: List[TreeNode]) -> TreeNode:
        min_val = min(node.val for node in nodes)
        max_val = max(node.val for node in nodes)

        cur = root
        while cur:
            if max_val < cur.val:
                cur = cur.left
            elif min_val > cur.val:
                cur = cur.right
            else:
                return cur
        return None