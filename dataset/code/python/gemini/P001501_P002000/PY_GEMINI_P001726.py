from collections import defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        prefix_count = defaultdict(int)
        prefix_count[0] = 1

        def dfs(node, cur_sum):
            if not node:
                return 0
            cur_sum += node.val
            res = prefix_count[cur_sum - targetSum]
            prefix_count[cur_sum] += 1
            res += dfs(node.left, cur_sum) + dfs(node.right, cur_sum)
            prefix_count[cur_sum] -= 1
            return res

        return dfs(root, 0)