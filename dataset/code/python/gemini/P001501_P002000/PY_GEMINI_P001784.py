from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, levelOrder: List[int], inorder: List[int]) -> TreeNode:
        if not levelOrder or not inorder:
            return None

        root = TreeNode(levelOrder[0])
        idx = inorder.index(levelOrder[0])

        left_inorder = set(inorder[:idx])
        right_inorder = set(inorder[idx + 1:])

        left_level = [x for x in levelOrder if x in left_inorder]
        right_level = [x for x in levelOrder if x in right_inorder]

        root.left = self.buildTree(left_level, inorder[:idx])
        root.right = self.buildTree(right_level, inorder[idx + 1:])
        return root