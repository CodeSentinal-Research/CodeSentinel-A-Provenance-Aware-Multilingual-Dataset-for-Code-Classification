from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def bstFromAncestorMatrix(self, matrix: List[List[int]]) -> TreeNode:
        n = len(matrix)
        if n == 0:
            return None

        # Number of 1s in row i indicates the number of descendants
        desc_count = [(sum(matrix[i]), i) for i in range(n)]
        desc_count.sort(reverse=True)

        root = TreeNode(desc_count[0][1])

        def insert(node, val):
            if not node:
                return TreeNode(val)
            if val < node.val:
                node.left = insert(node.left, val)
            else:
                node.right = insert(node.right, val)
            return node

        for _, val in desc_count[1:]:
            insert(root, val)

        return root