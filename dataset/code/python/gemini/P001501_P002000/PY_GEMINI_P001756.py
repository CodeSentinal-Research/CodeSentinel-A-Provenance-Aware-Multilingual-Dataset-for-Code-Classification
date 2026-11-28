class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def everyLeafHasSibling(self, root: TreeNode) -> bool:
        if not root:
            return True
        if not root.left and not root.right:
            return True
        if (root.left and not root.right and not root.left.left and not root.left.right) or            (root.right and not root.left and not root.right.left and not root.right.right):
            return False
        return self.everyLeafHasSibling(root.left) and self.everyLeafHasSibling(root.right)