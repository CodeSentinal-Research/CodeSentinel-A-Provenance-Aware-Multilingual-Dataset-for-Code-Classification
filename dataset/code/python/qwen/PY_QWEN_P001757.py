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

def nearest_common_leaf(root, u_val, v_val):
    # Find nodes
    def find_node(node, val):
        if not node:
            return None
        if node.val == val:
            return node
        left = find_node(node.left, val)
        if left:
            return left
        return find_node(node.right, val)
        
    u_node = find_node(root, u_val)
    v_node = find_node(root, v_val)
    
    if not u_node or not v_node:
        return None
        
    # BFS from u and v to find all leaves and distances
    def get_leaf_distances(start):
        dist_map = {} # leaf_val -> dist
        q = deque([(start, 0)])
        visited = set()
        visited.add(start)
        while q:
            node, d = q.popleft()
            if not node.left and not node.right:
                dist_map[node.val] = d
            # Need to go up too? Tree doesn't have parent pointers by default.
            # We need to convert to graph or add parent pointers.
            pass
        return dist_map
        
    # Add parent pointers
    parent_map = {}
    q = deque([root])
    while q:
        node = q.popleft()
        if node.left:
            parent_map[node.left] = node
            q.append(node.left)
        if node.right:
            parent_map[node.right] = node
            q.append(node.right)
            
    # BFS from u
    def bfs_dist(start):
        dist = {}
        q = deque([(start, 0)])
        visited = {start}
        while q:
            node, d = q.popleft()
            if not node.left and not node.right:
                dist[node.val] = d
            neighbors = []
            if node.left: neighbors.append(node.left)
            if node.right: neighbors.append(node.right)
            if node in parent_map: neighbors.append(parent_map[node])
            
            for nb in neighbors:
                if nb not in visited:
                    visited.add(nb)
                    q.append((nb, d + 1))
        return dist
        
    u_dists = bfs_dist(u_node)
    v_dists = bfs_dist(v_node)
    
    min_total = float('inf')
    best_leaf = None
    
    for leaf_val in u_dists:
        if leaf_val in v_dists:
            total = u_dists[leaf_val] + v_dists[leaf_val]
            if total < min_total:
                min_total = total
                best_leaf = leaf_val
                
    return best_leaf

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
        
    u = int(input_data[idx]); idx += 1
    v = int(input_data[idx]); idx += 1
    
    root = build_tree(vals)
    res = nearest_common_leaf(root, u, v)
    print(res if res is not None else "NONE")

solve()

