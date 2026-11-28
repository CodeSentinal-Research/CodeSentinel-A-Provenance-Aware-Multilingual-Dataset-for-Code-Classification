from collections import deque
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def constructBST(self, levelOrder: List[int]) -> TreeNode:
        if not levelOrder:
            return None

        root = TreeNode(levelOrder[0])
        dq = deque([(root, float('-inf'), float('inf'))])
        idx = 1

        while dq and idx < len(levelOrder):
            node, low, high = dq.popleft()

            if idx < len(levelOrder) and low < levelOrder[idx] < node.val:
                node.left = TreeNode(levelOrder[idx])
                idx += 1
                dq.append((node.left, low, node.val))

            if idx < len(levelOrder) and node.val < levelOrder[idx] < high:
                node.right = TreeNode(levelOrder[idx])
                idx += 1
                dq.append((node.right, node.val, high))

        return root