from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findClosestLeaf(self, root: TreeNode, k: int) -> int:
        parent_map = {}
        target_node = None

        def dfs(node, parent):
            nonlocal target_node
            if not node:
                return
            if node.val == k:
                target_node = node
            parent_map[node] = parent
            dfs(node.left, node)
            dfs(node.right, node)

        dfs(root, None)

        visited = {target_node}
        dq = deque([target_node])

        while dq:
            curr = dq.popleft()
            if not curr.left and not curr.right:
                return curr.val
            for neighbor in [curr.left, curr.right, parent_map[curr]]:
                if neighbor and neighbor not in visited:
                    visited.add(neighbor)
                    dq.append(neighbor)

        return -1