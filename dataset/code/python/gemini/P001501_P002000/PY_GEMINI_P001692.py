class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        if not root:
            return 0
        max_len = 0

        def dfs(node, parent, length):
            nonlocal max_len
            if not node:
                return
            if parent and node.val == parent.val + 1:
                length += 1
            else:
                length = 1
            max_len = max(max_len, length)
            dfs(node.left, node, length)
            dfs(node.right, node, length)

        dfs(root, None, 0)
        return max_len