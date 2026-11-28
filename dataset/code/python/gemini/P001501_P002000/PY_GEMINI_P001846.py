class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def canBeBSTByRotations(self, root: TreeNode) -> bool:
        # Rotations preserve the inorder traversal sequence.
        # Thus, a tree can be rotated into a BST if and only if its inorder traversal is strictly increasing.
        prev = float('-inf')
        possible = True

        def inorder(node):
            nonlocal prev, possible
            if not node or not possible:
                return
            inorder(node.left)
            if node.val <= prev:
                possible = False
                return
            prev = node.val
            inorder(node.right)

        inorder(root)
        return possible