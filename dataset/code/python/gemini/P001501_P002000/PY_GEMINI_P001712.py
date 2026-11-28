class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def convertTree(self, root: TreeNode) -> None:
        if not root or (not root.left and not root.right):
            return

        child_sum = (root.left.val if root.left else 0) + (root.right.val if root.right else 0)
        if child_sum >= root.val:
            root.val = child_sum
        else:
            if root.left: root.left.val = root.val
            if root.right: root.right.val = root.val

        self.convertTree(root.left)
        self.convertTree(root.right)

        tot = (root.left.val if root.left else 0) + (root.right.val if root.right else 0)
        if root.left or root.right:
            root.val = tot