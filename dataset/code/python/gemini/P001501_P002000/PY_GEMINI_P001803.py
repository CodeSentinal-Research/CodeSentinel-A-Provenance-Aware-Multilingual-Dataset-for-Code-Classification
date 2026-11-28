from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        def inorder(node, arr):
            if not node:
                return
            inorder(node.left, arr)
            arr.append(node.val)
            inorder(node.right, arr)

        arr1, arr2 = [], []
        inorder(root1, arr1)
        inorder(root2, arr2)

        merged = []
        i = j = 0
        while i < len(arr1) and j < len(arr2):
            if arr1[i] < arr2[j]:
                merged.append(arr1[i])
                i += 1
            else:
                merged.append(arr2[j])
                j += 1
        merged.extend(arr1[i:])
        merged.extend(arr2[j:])

        def build(l, r):
            if l > r:
                return None
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            node = TreeNode(merged[mid])
            node.left = build(l, mid - 1)
            node.right = build(mid + 1, r)
            return node

        return build(0, len(merged) - 1)