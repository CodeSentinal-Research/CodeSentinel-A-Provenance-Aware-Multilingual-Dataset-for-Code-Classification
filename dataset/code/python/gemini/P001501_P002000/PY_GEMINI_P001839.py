class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findTriplet(self, root: TreeNode, target: int) -> bool:
        vals = []

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            vals.append(node.val)
            inorder(node.right)

        inorder(root)
        n = len(vals)
        for i in range(n - 2):
            l, r = i + 1, n - 1
            while l < r:
                cur_sum = vals[i] + vals[l] + vals[r]
                if cur_sum == target:
                    return True
                elif cur_sum < target:
                    l += 1
                else:
                    r -= 1

        return False