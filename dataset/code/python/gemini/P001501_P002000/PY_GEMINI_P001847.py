class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def minRotationsToBalance(self, root: TreeNode) -> int:
        # Vine-to-tree balance (Day-Stout-Warren algorithm rotations count)
        def count_nodes(node):
            if not node:
                return 0
            return 1 + count_nodes(node.left) + count_nodes(node.right)

        n = count_nodes(root)
        if n <= 2:
            return 0

        # Number of leaves at the deepest level
        import math
        m = (1 << int(math.log2(n + 1))) - 1
        initial_rotations = n - m
        total_rotations = initial_rotations

        m //= 2
        while m > 0:
            total_rotations += m
            m //= 2

        return total_rotations