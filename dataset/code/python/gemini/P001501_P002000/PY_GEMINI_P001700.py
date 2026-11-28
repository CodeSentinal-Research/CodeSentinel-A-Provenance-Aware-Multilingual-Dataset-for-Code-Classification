class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def reverseOddLevels(self, root: TreeNode) -> TreeNode:
        if not root:
            return None

        def dfs(left, right, level):
            if not left or not right:
                return
            # If current bit is set, multiply base into result
            if level % 2 == 1:
                left.val, right.val = right.val, left.val
            dfs(left.left, right.right, level + 1)
            dfs(left.right, right.left, level + 1)

        dfs(root.left, root.right, 1)
        return root