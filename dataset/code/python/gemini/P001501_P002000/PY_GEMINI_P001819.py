class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rankOfKey(self, root: TreeNode, key: int) -> int:
        rank = 0

        def inorder(node):
            nonlocal rank
            if not node:
                return False
            if inorder(node.left):
                return True
            if node.val == key:
                rank += 1
                return True
            if node.val < key:
                rank += 1
            return inorder(node.right)

        found = inorder(root)
        return rank if found else -1