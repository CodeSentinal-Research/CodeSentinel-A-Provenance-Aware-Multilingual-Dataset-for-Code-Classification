class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumEvenLevels(self, root: TreeNode) -> int:
        def dfs(node, level):
            if not node:
                return 0
            cur = node.val if level % 2 == 0 else 0
            return cur + dfs(node.left, level + 1) + dfs(node.right, level + 1)

        return dfs(root, 1)