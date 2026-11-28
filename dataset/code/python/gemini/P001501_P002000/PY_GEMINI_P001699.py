from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        dq = deque([root])
        level = 0

        while dq:
            prev = None
            for _ in range(len(dq)):
                node = dq.popleft()
                if level % 2 == 0:
                    if node.val % 2 == 0 or (prev is not None and node.val <= prev):
                        return False
                else:
                    if node.val % 2 != 0 or (prev is not None and node.val >= prev):
                        return False
                prev = node.val
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            level += 1

        return True