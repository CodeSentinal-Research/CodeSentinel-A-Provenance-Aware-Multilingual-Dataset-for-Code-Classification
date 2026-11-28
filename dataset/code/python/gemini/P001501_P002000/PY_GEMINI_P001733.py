class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSumTree(self, root: TreeNode) -> bool:
        def check(node):
            if not node:
                return 0
            if not node.left and not node.right:
                return node.val
            l_sum = check(node.left)
            r_sum = check(node.right)
            if l_sum == -1 or r_sum == -1 or node.val != l_sum + r_sum:
                return -1
            return node.val + l_sum + r_sum

        return check(root) != -1