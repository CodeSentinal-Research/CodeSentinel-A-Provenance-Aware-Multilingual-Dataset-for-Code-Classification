class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestCompleteSubtree(self, root: TreeNode) -> int:
        max_size = 0

        # Returns (is_complete, is_perfect, height, size)
        def dfs(node):
            nonlocal max_size
            if not node:
                return True, True, 0, 0

            l_comp, l_perf, l_h, l_size = dfs(node.left)
            r_comp, r_perf, r_h, r_size = dfs(node.right)

            cur_size = l_size + r_size + 1

            if l_perf and r_comp and l_h == r_h:
                max_size = max(max_size, cur_size)
                return True, r_perf, l_h + 1, cur_size

            if l_comp and r_perf and l_h == r_h + 1:
                max_size = max(max_size, cur_size)
                return True, False, l_h + 1, cur_size

            return False, False, 0, 0

        dfs(root)
        return max_size