from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findLeaves(self, root: TreeNode) -> List[List[int]]:
        res = []

        def dfs(node):
            if not node:
                return -1
            height = 1 + max(dfs(node.left), dfs(node.right))
            if height == len(res):
                res.append([])
            res[height].append(node.val)
            return height

        dfs(root)
        return res