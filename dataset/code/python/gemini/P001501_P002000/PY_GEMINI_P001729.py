class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findDistance(self, root: TreeNode, p: int, q: int) -> int:
        if p == q:
            return 0

        def lca(node):
            if not node or node.val == p or node.val == q:
                return node
            l = lca(node.left)
            r = lca(node.right)
            if l and r: return node
            return l if l else r

        def dist(node, target):
            if not node:
                return -1
            if node.val == target:
                return 0
            d = dist(node.left, target)
            if d >= 0: return d + 1
            d = dist(node.right, target)
            if d >= 0: return d + 1
            return -1

        ancestor = lca(root)
        return dist(ancestor, p) + dist(ancestor, q)