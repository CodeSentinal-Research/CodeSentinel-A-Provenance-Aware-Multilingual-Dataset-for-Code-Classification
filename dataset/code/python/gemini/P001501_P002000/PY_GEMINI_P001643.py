from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        dq = deque([(root, 0)])
        max_width = 0

        while dq:
            level_len = len(dq)
            _, first_idx = dq[0]
            _, last_idx = dq[-1]
            max_width = max(max_width, last_idx - first_idx + 1)

            for _ in range(level_len):
                node, idx = dq.popleft()
                cur_idx = idx - first_idx
                if node.left:
                    dq.append((node.left, 2 * cur_idx))
                if node.right:
                    dq.append((node.right, 2 * cur_idx + 1))

        return max_width