from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findClosestPair(self, root1: TreeNode, root2: TreeNode, target: int) -> List[int]:
        def inorder(node, arr):
            if not node:
                return
            inorder(node.left, arr)
            arr.append(node.val)
            inorder(node.right, arr)

        arr1, arr2 = [], []
        inorder(root1, arr1)
        inorder(root2, arr2)

        i, j = 0, len(arr2) - 1
        best_diff = float('inf')
        res = [arr1[0], arr2[-1]]

        while i < len(arr1) and j >= 0:
            cur_sum = arr1[i] + arr2[j]
            diff = abs(cur_sum - target)
            if diff < best_diff:
                best_diff = diff
                res = [arr1[i], arr2[j]]

            if cur_sum < target:
                i += 1
            else:
                j -= 1

        return res