class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestUnivalueSubtree(self, root: TreeNode) -> int:
        max_size = 0

        # Returns (is_unival, size)
        def dfs(node):
            nonlocal max_size
            if not node:
                return True, 0
            l_unival, l_size = dfs(node.left)
            r_unival, r_size = dfs(node.right)

            if l_unival and r_unival:
                if (not node.left or node.left.val == node.val) and (not node.right or node.right.val == node.val):
                    cur_size = l_size + r_size + 1
                    max_size = max(max_size, cur_size)
                    return True, cur_size

            return False, 0

        dfs(root)
        return max_size