from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildCartesianTree(self, inorder: List[int]) -> TreeNode:
        stack = []

        for val in inorder:
            last = None
            # Maintain monotonic stack property by popping smaller elements
            while stack and stack[-1].val > val:
                last = stack.pop()
            node = TreeNode(val)
            node.left = last
            if stack:
                stack[-1].right = node
            stack.append(node)

        return stack[0] if stack else None