from collections import deque
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parent_map = {}

        def map_parents(node, parent):
            if not node:
                return
            parent_map[node] = parent
            map_parents(node.left, node)
            map_parents(node.right, node)

        map_parents(root, None)

        visited = {target}
        dq = deque([(target, 0)])
        res = []

        while dq:
            node, dist = dq.popleft()
            if dist == k:
                res.append(node.val)
            elif dist < k:
                for neighbor in [node.left, node.right, parent_map[node]]:
                    if neighbor and neighbor not in visited:
                        visited.add(neighbor)
                        dq.append((neighbor, dist + 1))

        return res