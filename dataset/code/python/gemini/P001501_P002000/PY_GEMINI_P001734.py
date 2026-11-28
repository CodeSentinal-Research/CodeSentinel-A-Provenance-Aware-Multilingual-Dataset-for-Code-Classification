class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def toSumTree(self, root: TreeNode) -> None:
        def convert(node):
            if not node:
                return 0
            old_val = node.val
            l_sum = convert(node.left)
            r_sum = convert(node.right)
            node.val = l_sum + r_sum
            return node.val + old_val

        convert(root)