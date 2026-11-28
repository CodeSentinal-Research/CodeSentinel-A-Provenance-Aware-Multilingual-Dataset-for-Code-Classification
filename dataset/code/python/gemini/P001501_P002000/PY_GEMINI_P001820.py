class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def keyWithRank(self, root: TreeNode, rank: int) -> int:
        cur_rank = 0
        ans = -1

        def inorder(node):
            nonlocal cur_rank, ans
            if not node or ans != -1:
                return
            inorder(node.left)
            cur_rank += 1
            if cur_rank == rank:
                ans = node.val
                return
            inorder(node.right)

        inorder(root)
        return ans