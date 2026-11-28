from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def firstNonFullNode(self, root: TreeNode) -> int:
        if not root:
            return -1
        dq = deque([root])

        while dq:
            node = dq.popleft()
            if not node.left or not node.right:
                return node.val
            dq.append(node.left)
            dq.append(node.right)

        return -1