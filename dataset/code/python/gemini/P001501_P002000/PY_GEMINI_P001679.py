from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        if not root:
            return 0
        dq = deque([root])
        max_sum = float('-inf')
        max_level = cur_level = 1

        while dq:
            level_sum = 0
            for _ in range(len(dq)):
                node = dq.popleft()
                level_sum += node.val
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)

            if level_sum > max_sum:
                max_sum = level_sum
                max_level = cur_level
            cur_level += 1

        return max_level