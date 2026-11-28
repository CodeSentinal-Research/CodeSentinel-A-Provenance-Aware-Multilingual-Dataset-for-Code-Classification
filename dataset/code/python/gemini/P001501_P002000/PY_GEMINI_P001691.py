class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rob(self, root: TreeNode) -> int:
        # Returns (rob_this_node, skip_this_node)
        def dfs(node):
            if not node:
                return 0, 0
            l_rob, l_skip = dfs(node.left)
            r_rob, r_skip = dfs(node.right)

            rob_cur = node.val + l_skip + r_skip
            skip_cur = max(l_rob, l_skip) + max(r_rob, r_skip)
            return rob_cur, skip_cur

        return max(dfs(root))