class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestPerfectSubtree(self, root: TreeNode) -> int:
        max_size = 0

        # Returns depth if perfect, else -1
        def dfs(node):
            nonlocal max_size
            if not node:
                return 0
            l = dfs(node.left)
            r = dfs(node.right)

            if l != -1 and r != -1 and l == r:
                depth = l + 1
                size = (1 << depth) - 1
                max_size = max(max_size, size)
                return depth

            return -1

        dfs(root)
        return max_size