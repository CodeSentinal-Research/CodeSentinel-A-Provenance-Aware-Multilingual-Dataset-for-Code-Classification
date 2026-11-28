class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def convertToDescendantSum(self, root: TreeNode) -> TreeNode:
        def dfs(node):
            if not node:
                return 0
            l_sum = dfs(node.left)
            r_sum = dfs(node.right)
            old_val = node.val
            node.val = l_sum + r_sum
            return node.val + old_val

        dfs(root)
        return root