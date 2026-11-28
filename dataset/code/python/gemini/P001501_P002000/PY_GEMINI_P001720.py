from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        if not root:
            return 0
        dq = deque([root])
        level_sum = 0

        while dq:
            level_sum = 0
            for _ in range(len(dq)):
                node = dq.popleft()
                level_sum += node.val
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)

        return level_sum