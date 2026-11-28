from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLeafLevel(self, root: TreeNode) -> int:
        if not root:
            return 0
        dq = deque([root])
        max_leaves = -1
        max_level = cur_level = 1

        while dq:
            leaf_count = 0
            for _ in range(len(dq)):
                node = dq.popleft()
                if not node.left and not node.right:
                    leaf_count += 1
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)

            if leaf_count > max_leaves:
                max_leaves = leaf_count
                max_level = cur_level
            cur_level += 1

        return max_level