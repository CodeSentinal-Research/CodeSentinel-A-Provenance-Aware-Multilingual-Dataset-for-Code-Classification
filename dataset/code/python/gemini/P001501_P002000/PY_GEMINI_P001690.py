class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        max_sum = 0

        # Returns (is_bst, min_val, max_val, total_sum)
        def dfs(node):
            nonlocal max_sum
            if not node:
                return True, float('inf'), float('-inf'), 0

            l_bst, l_min, l_max, l_sum = dfs(node.left)
            r_bst, r_min, r_max, r_sum = dfs(node.right)

            if l_bst and r_bst and l_max < node.val < r_min:
                cur_sum = l_sum + r_sum + node.val
                max_sum = max(max_sum, cur_sum)
                return True, min(l_min, node.val), max(r_max, node.val), cur_sum

            return False, 0, 0, 0

        dfs(root)
        return max_sum