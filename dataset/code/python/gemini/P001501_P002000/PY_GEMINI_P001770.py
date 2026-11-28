from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def replaceWithLevelSum(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        dq = deque([root])

        while dq:
            size = len(dq)
            level_nodes = []
            level_sum = 0
            for _ in range(size):
                node = dq.popleft()
                level_nodes.append(node)
                level_sum += node.val
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            for node in level_nodes:
                node.val = level_sum

        return root