class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        res = {}

        def dfs(node, parent, depth):
            if not node:
                return
            if node.val == x or node.val == y:
                res[node.val] = (parent, depth)
            dfs(node.left, node, depth + 1)
            dfs(node.right, node, depth + 1)

        dfs(root, None, 0)
        return res[x][1] == res[y][1] and res[x][0] != res[y][0]