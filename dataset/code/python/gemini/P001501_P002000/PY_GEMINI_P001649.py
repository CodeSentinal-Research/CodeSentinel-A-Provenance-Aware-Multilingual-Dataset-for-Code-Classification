from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        in_map = {val: i for i, val in enumerate(inorder)}
        self.pre_idx = 0

        def build(in_start, in_end):
            if in_start > in_end:
                return None
            root_val = preorder[self.pre_idx]
            self.pre_idx += 1
            root = TreeNode(root_val)
            mid = in_map[root_val]

            root.left = build(in_start, mid - 1)
            root.right = build(mid + 1, in_end)
            return root

        return build(0, len(inorder) - 1)