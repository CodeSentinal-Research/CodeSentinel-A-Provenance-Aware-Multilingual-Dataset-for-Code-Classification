class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfLargestBST(self, root: TreeNode) -> int:
        max_bst_size = 0
        best_diameter = 0

        # Returns (is_bst, size, height, diameter, min_v, max_v)
        def dfs(node):
            nonlocal max_bst_size, best_diameter
            if not node:
                return True, 0, 0, 0, float('inf'), float('-inf')

            l_bst, l_sz, l_h, l_d, l_min, l_max = dfs(node.left)
            r_bst, r_sz, r_h, r_d, r_min, r_max = dfs(node.right)

            if l_bst and r_bst and l_max < node.val < r_min:
                cur_sz = l_sz + r_sz + 1
                cur_h = 1 + max(l_h, r_h)
                cur_d = max(l_h + r_h, max(l_d, r_d))

                if cur_sz > max_bst_size:
                    max_bst_size = cur_sz
                    best_diameter = cur_d

                return True, cur_sz, cur_h, cur_d, min(l_min, node.val), max(r_max, node.val)

            return False, 0, 0, 0, 0, 0

        dfs(root)
        return best_diameter