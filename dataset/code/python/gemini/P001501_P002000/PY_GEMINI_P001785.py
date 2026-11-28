class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxIndependentSet(self, root: TreeNode) -> int:
        # Returns (incl, excl)
        def dfs(node):
            if not node:
                return 0, 0
            l_incl, l_excl = dfs(node.left)
            r_incl, r_excl = dfs(node.right)

            incl = 1 + l_excl + r_excl
            excl = max(l_incl, l_excl) + max(r_incl, r_excl)
            return incl, excl

        return max(dfs(root))