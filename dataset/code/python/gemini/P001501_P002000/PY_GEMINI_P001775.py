from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxAdjacentLevelDiff(self, root: TreeNode) -> int:
        if not root:
            return 0
        dq = deque([root])
        level_sums = []

        while dq:
            size = len(dq)
            cur_sum = 0
            for _ in range(size):
                node = dq.popleft()
                cur_sum += node.val
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            level_sums.append(cur_sum)

        max_diff = 0
        for i in range(1, len(level_sums)):
            max_diff = max(max_diff, abs(level_sums[i] - level_sums[i - 1]))
        return max_diff