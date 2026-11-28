from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrderPredecessor(self, root: TreeNode, target_val: int) -> int:
        if not root:
            return -1
        dq = deque([root])
        prev_val = -1

        while dq:
            node = dq.popleft()
            if node.val == target_val:
                return prev_val
            prev_val = node.val
            if node.left: dq.append(node.left)
            if node.right: dq.append(node.right)

        return -1