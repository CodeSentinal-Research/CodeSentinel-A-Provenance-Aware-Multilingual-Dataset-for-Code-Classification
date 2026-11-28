class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestPerfectBSTSubtree(self, root: TreeNode) -> int:
        max_size = 0

        # Returns (is_bst, is_perf, height, min_v, max_v)
        def dfs(node):
            nonlocal max_size
            if not node:
                return True, True, 0, float('inf'), float('-inf')

            l_bst, l_perf, l_h, l_min, l_max = dfs(node.left)
            r_bst, r_perf, r_h, r_min, r_max = dfs(node.right)

            is_bst = l_bst and r_bst and l_max < node.val < r_min
            min_v = min(l_min, node.val)
            max_v = max(r_max, node.val)

            if is_bst and l_perf and r_perf and l_h == r_h:
                cur_h = l_h + 1
                size = (1 << cur_h) - 1
                max_size = max(max_size, size)
                return True, True, cur_h, min_v, max_v

            return False, False, 0, 0, 0

        dfs(root)
        return max_size