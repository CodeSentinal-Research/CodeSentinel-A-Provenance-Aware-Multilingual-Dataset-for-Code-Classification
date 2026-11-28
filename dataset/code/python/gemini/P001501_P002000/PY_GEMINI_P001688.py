class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        all_sums = []

        def tree_sum(node):
            if not node:
                return 0
            cur = node.val + tree_sum(node.left) + tree_sum(node.right)
            all_sums.append(cur)
            return cur

        total = tree_sum(root)
        max_prod = 0
        MOD = 10**9 + 7

        for s in all_sums:
            max_prod = max(max_prod, s * (total - s))

        return max_prod % MOD