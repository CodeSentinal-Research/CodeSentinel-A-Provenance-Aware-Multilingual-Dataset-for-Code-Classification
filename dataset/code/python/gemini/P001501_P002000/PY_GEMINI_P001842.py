from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def unionBST(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inorder(node, arr):
            if not node:
                return
            inorder(node.left, arr)
            arr.append(node.val)
            inorder(node.right, arr)

        arr1, arr2 = [], []
        inorder(root1, arr1)
        inorder(root2, arr2)

        res = []
        i = j = 0
        while i < len(arr1) and j < len(arr2):
            if arr1[i] == arr2[j]:
                res.append(arr1[i])
                i += 1
                j += 1
            elif arr1[i] < arr2[j]:
                res.append(arr1[i])
                i += 1
            else:
                res.append(arr2[j])
                j += 1

        while i < len(arr1):
            res.append(arr1[i])
            i += 1
        while j < len(arr2):
            res.append(arr2[j])
            j += 1

        return res