from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrderSuccessor(self, root: TreeNode, target_val: int) -> int:
        if not root:
            return -1
        dq = deque([root])
        found = False

        while dq:
            node = dq.popleft()
            if found:
                return node.val
            if node.val == target_val:
                found = True
            if node.left: dq.append(node.left)
            if node.right: dq.append(node.right)

        return -1