class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isPerfect(self, root: TreeNode) -> bool:
        def depth(node):
            d = 0
            while node:
                d += 1
                node = node.left
            return d

        d = depth(root)

        def check(node, level):
            if not node:
                return True
            if not node.left and not node.right:
                return level == d
            if not node.left or not node.right:
                return False
            return check(node.left, level + 1) and check(node.right, level + 1)

        return check(root, 1)