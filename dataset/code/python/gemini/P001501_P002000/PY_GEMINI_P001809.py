class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        cur_sum = 0

        def reverse_inorder(node):
            nonlocal cur_sum
            if not node:
                return
            reverse_inorder(node.right)
            cur_sum += node.val
            node.val = cur_sum
            reverse_inorder(node.left)

        reverse_inorder(root)
        return root