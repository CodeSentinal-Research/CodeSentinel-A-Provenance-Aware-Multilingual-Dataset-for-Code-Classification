class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def minInsertionsToCompleteBST(self, root: TreeNode) -> int:
        def count_nodes(node):
            if not node:
                return 0
            return 1 + count_nodes(node.left) + count_nodes(node.right)

        def get_height(node):
            if not node:
                return 0
            return 1 + max(get_height(node.left), get_height(node.right))

        n = count_nodes(root)
        h = get_height(root)
        min_nodes_for_height = 1 << (h - 1)
        if n >= min_nodes_for_height:
            return 0
        return min_nodes_for_height - n