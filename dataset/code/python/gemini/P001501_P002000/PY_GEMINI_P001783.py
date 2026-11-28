class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findCentroid(self, root: TreeNode) -> int:
        def count_nodes(node):
            if not node:
                return 0
            return 1 + count_nodes(node.left) + count_nodes(node.right)

        total_nodes = count_nodes(root)
        centroid = -1

        def dfs(node):
            nonlocal centroid
            if not node:
                return 0
            l = dfs(node.left)
            r = dfs(node.right)
            parent_size = total_nodes - (1 + l + r)

            if l <= total_nodes // 2 and r <= total_nodes // 2 and parent_size <= total_nodes // 2:
                centroid = node.val

            return 1 + l + r

        dfs(root)
        return centroid