class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def bstToCumulative(self, root: TreeNode) -> TreeNode:
        cur_sum = 0

        def inorder(node):
            nonlocal cur_sum
            if not node:
                return
            inorder(node.left)
            cur_sum += node.val
            node.val = cur_sum
            inorder(node.right)

        inorder(root)
        return root