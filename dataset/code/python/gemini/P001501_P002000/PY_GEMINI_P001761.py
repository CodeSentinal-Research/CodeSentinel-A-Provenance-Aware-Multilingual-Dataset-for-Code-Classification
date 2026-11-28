class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxSubtreeSum(self, root: TreeNode) -> int:
        max_sum = float('-inf')

        def dfs(node):
            nonlocal max_sum
            if not node:
                return 0
            cur_sum = node.val + dfs(node.left) + dfs(node.right)
            max_sum = max(max_sum, cur_sum)
            return cur_sum

        dfs(root)
        return max_sum