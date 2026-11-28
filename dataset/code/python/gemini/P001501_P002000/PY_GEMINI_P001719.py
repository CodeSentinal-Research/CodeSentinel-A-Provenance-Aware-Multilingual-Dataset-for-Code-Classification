from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def longestPath(self, root: TreeNode) -> List[int]:
        longest = []

        def dfs(node, path):
            nonlocal longest
            if not node:
                return
            path.append(node.val)
            if not node.left and not node.right:
                if len(path) > len(longest):
                    longest = list(path)
            else:
                dfs(node.left, path)
                dfs(node.right, path)
            path.pop()

        dfs(root, [])
        return longest