from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        in_map = {val: i for i, val in enumerate(inorder)}
        self.post_idx = len(postorder) - 1

        def build(in_start, in_end):
            if in_start > in_end:
                return None
            root_val = postorder[self.post_idx]
            self.post_idx -= 1
            root = TreeNode(root_val)
            mid = in_map[root_val]

            root.right = build(mid + 1, in_end)
            root.left = build(in_start, mid - 1)
            return root

        return build(0, len(inorder) - 1)