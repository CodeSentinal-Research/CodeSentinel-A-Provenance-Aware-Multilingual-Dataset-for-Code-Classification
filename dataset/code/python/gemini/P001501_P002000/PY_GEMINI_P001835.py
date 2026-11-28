class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestDeadEndFreeSubtree(self, root: TreeNode) -> int:
        max_size = 0

        # Returns (is_dead_end_free, size)
        def dfs(node, low, high):
            nonlocal max_size
            if not node:
                return True, 0
            if low == high:
                return False, 0

            l_free, l_sz = dfs(node.left, low, node.val - 1)
            r_free, r_sz = dfs(node.right, node.val + 1, high)

            if l_free and r_free:
                cur_size = l_sz + r_sz + 1
                max_size = max(max_size, cur_size)
                return True, cur_size

            return False, 0

        dfs(root, 1, float('inf'))
        return max_size