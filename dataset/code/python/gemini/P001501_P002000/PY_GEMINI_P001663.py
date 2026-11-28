from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        dq = deque([root])
        saw_null = False

        while dq:
            node = dq.popleft()
            if not node:
                saw_null = True
            else:
                if saw_null:
                    return False
                dq.append(node.left)
                dq.append(node.right)

        return True