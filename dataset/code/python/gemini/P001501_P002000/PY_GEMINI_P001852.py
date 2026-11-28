import math

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countValidInsertionSeqs(self, root: TreeNode) -> int:
        MOD = 10**9 + 7

        # Returns (count_seqs, subtree_size)
        def dfs(node):
            if not node:
                return 1, 0
            l_count, l_size = dfs(node.left)
            r_count, r_size = dfs(node.right)

            comb = math.comb(l_size + r_size, l_size) % MOD
            ways = (l_count * r_count % MOD) * comb % MOD
            return ways, l_size + r_size + 1

        return dfs(root)[0]