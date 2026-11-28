class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countMonotonicPaths(self, root: TreeNode) -> int:
        if not root:
            return 0
        count = 0

        # is_inc: True/False, is_dec: True/False
        def dfs(node, parent_val, is_inc, is_dec):
            nonlocal count
            if not node:
                return
            if parent_val is not None:
                if node.val < parent_val:
                    is_inc = False
                if node.val > parent_val:
                    is_dec = False

            if not node.left and not node.right:
                if is_inc or is_dec:
                    count += 1
                return

            dfs(node.left, node.val, is_inc, is_dec)
            dfs(node.right, node.val, is_inc, is_dec)

        dfs(root, None, True, True)
        return count