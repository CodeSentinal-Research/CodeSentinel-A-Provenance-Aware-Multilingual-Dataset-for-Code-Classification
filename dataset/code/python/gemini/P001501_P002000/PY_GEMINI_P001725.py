class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 1 if root.val == targetSum else 0
        return self.pathSum(root.left, targetSum - root.val) + self.pathSum(root.right, targetSum - root.val)