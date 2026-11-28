class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isStructurallyIdentical(self, root1: TreeNode, root2: TreeNode) -> bool:
        if not root1 and not root2:
            return True
        if not root1 or not root2:
            return False
        return self.isStructurallyIdentical(root1.left, root2.left) and                self.isStructurallyIdentical(root1.right, root2.right)