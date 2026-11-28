from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def topView(self, root: TreeNode) -> list:
        if not root:
            return []
        col_map = {}
        dq = deque([(root, 0)])

        while dq:
            node, col = dq.popleft()
            if col not in col_map:
                col_map[col] = node.val
            if node.left:
                dq.append((node.left, col - 1))
            if node.right:
                dq.append((node.right, col + 1))

        return [col_map[c] for c in sorted(col_map.keys())]