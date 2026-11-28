import sys
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree(nodes):
    if not nodes:
        return None
    root = TreeNode(nodes[0])
    queue = [root]
    i = 1
    while queue and i < len(nodes):
        node = queue.pop(0)
        if i < len(nodes) and nodes[i] is not None:
            node.left = TreeNode(nodes[i])
            queue.append(node.left)
        i += 1
        if i < len(nodes) and nodes[i] is not None:
            node.right = TreeNode(nodes[i])
            queue.append(node.right)
        i += 1
    return root

def closest_leaf(root, target):
    if not root:
        return -1
        
    parent_map = {}
    target_node = None
    leaves = []
    q = deque([root])
    while q:
        node = q.popleft()
        if node.val == target:
            target_node = node
        if not node.left and not node.right:
            leaves.append(node)
        if node.left:
            parent_map[node.left] = node
            q.append(node.left)
        if node.right:
            parent_map[node.right] = node
            q.append(node.right)
            
    if not target_node:
        return -1
        
    min_dist = float('inf')
    result = -1
    
    for leaf in leaves:
        # Calculate distance
        path_set = set()
        curr = leaf
        while curr:
            path_set.add(curr)
            curr = parent_map.get(curr)
            
        curr = target_node
        dist = 0
        found = False
        while curr:
            if curr in path_set:
                # Dist from target to LCA + Dist from leaf to LCA
                # Simpler: BFS from target
                pass
            curr = parent_map.get(curr)
            
    # BFS from target is easier
    visited = set()
    q = deque([(target_node, 0)])
    visited.add(target_node)
    
    while q:
        node, dist = q.popleft()
        if not node.left and not node.right:
            return node.val
        if node.left and node.left not in visited:
            visited.add(node.left)
            q.append((node.left, dist + 1))
        if node.right and node.right not in visited:
            visited.add(node.right)
            q.append((node.right, dist + 1))
        if node in parent_map and parent_map[node] not in visited:
            visited.add(parent_map[node])
            q.append((parent_map[node], dist + 1))
            
    return -1

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    vals = []
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    target = int(input_data[idx])
    
    root = build_tree(vals)
    print(closest_leaf(root, target))

solve()

