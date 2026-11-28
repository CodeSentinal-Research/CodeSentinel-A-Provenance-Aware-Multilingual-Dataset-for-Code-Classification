class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestSymmetricSubtree(self, root: TreeNode) -> int:
        max_size = 0

        def is_mirror(t1, t2):
            if not t1 and not t2:
                return True
            if not t1 or not t2 or t1.val != t2.val:
                return False
            return is_mirror(t1.left, t2.right) and is_mirror(t1.right, t2.left)

        def tree_size(node):
            if not node:
                return 0
            return 1 + tree_size(node.left) + tree_size(node.right)

        def dfs(node):
            nonlocal max_size
            if not node:
                return
            if is_mirror(node.left, node.right):
                max_size = max(max_size, tree_size(node))
            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return max_size