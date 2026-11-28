from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> TreeNode:
        self.pre_idx = 0
        post_map = {val: i for i, val in enumerate(postorder)}

        def build(post_start, post_end):
            if post_start > post_end or self.pre_idx >= len(preorder):
                return None
            root = TreeNode(preorder[self.pre_idx])
            self.pre_idx += 1

            if post_start == post_end or self.pre_idx >= len(preorder):
                return root

            next_val = preorder[self.pre_idx]
            if next_val not in post_map or post_map[next_val] > post_end:
                return root

            mid = post_map[next_val]
            root.left = build(post_start, mid)
            root.right = build(mid + 1, post_end - 1)
            return root

        return build(0, len(postorder) - 1)