class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countAncestors(self, root: TreeNode) -> dict:
        ancestor_count = {}

        def dfs(node, depth):
            if not node:
                return
            ancestor_count[node.val] = depth
            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)

        dfs(root, 0)
        return ancestor_count