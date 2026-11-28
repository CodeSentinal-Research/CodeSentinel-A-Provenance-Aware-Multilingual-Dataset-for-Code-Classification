from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def minNodesLevel(self, root: TreeNode) -> int:
        if not root:
            return 0
        dq = deque([root])
        min_nodes = float('inf')
        min_level = cur_level = 1

        while dq:
            size = len(dq)
            if size < min_nodes:
                min_nodes = size
                min_level = cur_level

            for _ in range(size):
                node = dq.popleft()
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            cur_level += 1

        return min_level