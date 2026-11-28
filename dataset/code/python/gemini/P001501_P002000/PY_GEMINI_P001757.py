class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def nearestCommonLeaf(self, root: TreeNode, p: int, q: int) -> int:
        def lca(node):
            if not node or node.val == p or node.val == q:
                return node
            l = lca(node.left)
            r = lca(node.right)
            if l and r: return node
            return l if l else r

        ancestor = lca(root)
        min_depth = float('inf')
        res = -1

        def find_leaf(node, depth):
            nonlocal min_depth, res
            if not node:
                return
            if not node.left and not node.right:
                if depth < min_depth:
                    min_depth = depth
                    res = node.val
                return
            find_leaf(node.left, depth + 1)
            find_leaf(node.right, depth + 1)

        find_leaf(ancestor, 0)
        return res