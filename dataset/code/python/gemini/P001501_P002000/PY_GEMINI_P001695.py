class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def dfs(node, cur_val):
            if not node:
                return 0
            cur_val = (cur_val << 1) | node.val
            if not node.left and not node.right:
                return cur_val
            return dfs(node.left, cur_val) + dfs(node.right, cur_val)

        return dfs(root, 0)