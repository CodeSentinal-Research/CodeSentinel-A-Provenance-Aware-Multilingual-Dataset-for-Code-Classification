class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def minSubtreeSum(self, root: TreeNode) -> int:
        min_sum = float('inf')

        def dfs(node):
            nonlocal min_sum
            if not node:
                return 0
            cur_sum = node.val + dfs(node.left) + dfs(node.right)
            min_sum = min(min_sum, cur_sum)
            return cur_sum

        dfs(root)
        return min_sum