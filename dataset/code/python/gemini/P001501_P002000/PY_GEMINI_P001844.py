class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestCompleteBSTSubtree(self, root: TreeNode) -> int:
        max_size = 0

        # Returns (is_bst, is_comp, is_perf, height, size, min_v, max_v)
        def dfs(node):
            nonlocal max_size
            if not node:
                return True, True, True, 0, 0, float('inf'), float('-inf')

            l_bst, l_comp, l_perf, l_h, l_sz, l_min, l_max = dfs(node.left)
            r_bst, r_comp, r_perf, r_h, r_sz, r_min, r_max = dfs(node.right)

            is_bst = l_bst and r_bst and l_max < node.val < r_min
            cur_sz = l_sz + r_sz + 1
            min_v = min(l_min, node.val)
            max_v = max(r_max, node.val)

            if is_bst:
                if l_perf and r_comp and l_h == r_h:
                    max_size = max(max_size, cur_sz)
                    return True, True, r_perf, l_h + 1, cur_sz, min_v, max_v
                if l_comp and r_perf and l_h == r_h + 1:
                    max_size = max(max_size, cur_sz)
                    return True, True, False, l_h + 1, cur_sz, min_v, max_v

            return False, False, False, 0, 0, 0, 0

        dfs(root)
        return max_size