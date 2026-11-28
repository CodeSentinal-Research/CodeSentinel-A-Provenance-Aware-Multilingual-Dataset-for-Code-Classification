class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isFoldable(self, root: TreeNode) -> bool:
        if not root:
            return True

        def is_foldable_mirror(t1, t2):
            if not t1 and not t2:
                return True
            if not t1 or not t2:
                return False
            return is_foldable_mirror(t1.left, t2.right) and is_foldable_mirror(t1.right, t2.left)

        return is_foldable_mirror(root.left, root.right)