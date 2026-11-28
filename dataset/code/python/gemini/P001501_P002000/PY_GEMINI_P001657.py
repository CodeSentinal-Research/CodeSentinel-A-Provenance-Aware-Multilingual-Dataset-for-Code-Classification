from collections import deque, defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def minTimeToBurn(self, root: TreeNode, start: int) -> int:
        parent_map = {}
        target_node = None

        def map_parents(node, parent):
            nonlocal target_node
            if not node:
                return
            if node.val == start:
                target_node = node
            parent_map[node] = parent
            map_parents(node.left, node)
            map_parents(node.right, node)

        map_parents(root, None)

        visited = {target_node}
        dq = deque([target_node])
        time = 0

        while dq:
            size = len(dq)
            burned_any = False
            for _ in range(size):
                curr = dq.popleft()
                for neighbor in [curr.left, curr.right, parent_map[curr]]:
                    if neighbor and neighbor not in visited:
                        visited.add(neighbor)
                        dq.append(neighbor)
                        burned_any = True
            if burned_any:
                time += 1

        return time