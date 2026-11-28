from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def numDistinctShapes(self, seqs: List[List[int]]) -> int:
        def insert(root, val):
            if not root:
                return TreeNode(val)
            if val < root.val:
                root.left = insert(root.left, val)
            else:
                root.right = insert(root.right, val)
            return root

        def serialize_shape(root):
            if not root:
                return "#"
            return "(" + serialize_shape(root.left) + "," + serialize_shape(root.right) + ")"

        shapes = set()
        for seq in seqs:
            root = None
            for x in seq:
                root = insert(root, x)
            shapes.add(serialize_shape(root))

        return len(shapes)