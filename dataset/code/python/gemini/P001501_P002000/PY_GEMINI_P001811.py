class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        max_size = 0

        # Returns (is_bst, size, min_val, max_val)
        def dfs(node):
            nonlocal max_size
            if not node:
                return True, 0, float('inf'), float('-inf')

            l_bst, l_size, l_min, l_max = dfs(node.left)
            r_bst, r_size, r_min, r_max = dfs(node.right)

            if l_bst and r_bst and l_max < node.val < r_min:
                cur_size = l_size + r_size + 1
                max_size = max(max_size, cur_size)
                return True, cur_size, min(l_min, node.val), max(r_max, node.val)

            return False, 0, 0, 0

        dfs(root)
        return max_size