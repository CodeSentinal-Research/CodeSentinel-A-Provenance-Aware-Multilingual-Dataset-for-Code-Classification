class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countPairs(self, root1: TreeNode, root2: TreeNode, target: int) -> int:
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
        count = 0

        while i < len(arr1) and j >= 0:
            cur_sum = arr1[i] + arr2[j]
            if cur_sum == target:
                count += 1
                i += 1
                j -= 1
            elif cur_sum < target:
                i += 1
            else:
                j -= 1

        return count