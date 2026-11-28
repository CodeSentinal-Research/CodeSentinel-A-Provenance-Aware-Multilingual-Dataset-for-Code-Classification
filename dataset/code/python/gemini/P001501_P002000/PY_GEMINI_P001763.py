class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        count = 0

        def dfs(node):
            nonlocal count
            if not node:
                return True
            l = dfs(node.left)
            r = dfs(node.right)

            if l and r:
                if (not node.left or node.left.val == node.val) and (not node.right or node.right.val == node.val):
                    count += 1
                    return True
            return False

        dfs(root)
        return count