import sys

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

def count_monotonic_paths(root):
    count = 0
    
    def helper(node, prev_val, is_increasing, is_decreasing):
        nonlocal count
        if not node:
            return
        if not node.left and not node.right:
            if is_increasing or is_decreasing:
                count += 1
            return
            
        if node.left:
            new_inc = is_increasing and node.left.val > node.val
            new_dec = is_decreasing and node.left.val < node.val
            if not is_increasing and not is_decreasing:
                 # Start of path
                 if node.left.val > node.val: new_inc = True
                 elif node.left.val < node.val: new_dec = True
            helper(node.left, node.val, new_inc, new_dec)
            
        if node.right:
            new_inc = is_increasing and node.right.val > node.val
            new_dec = is_decreasing and node.right.val < node.val
            if not is_increasing and not is_decreasing:
                 if node.right.val > node.val: new_inc = True
                 elif node.right.val < node.val: new_dec = True
            helper(node.right, node.val, new_inc, new_dec)
            
    # This logic is tricky for "strictly increasing OR decreasing".
    # Simpler: Check all root-to-leaf paths.
    paths = []
    def get_paths(node, path):
        if not node:
            return
        path.append(node.val)
        if not node.left and not node.right:
            paths.append(path[:])
        get_paths(node.left, path)
        get_paths(node.right, path)
        path.pop()
        
    get_paths(root, [])
    for p in paths:
        if len(p) < 2:
            continue
        inc = all(p[i] < p[i+1] for i in range(len(p)-1))
        dec = all(p[i] > p[i+1] for i in range(len(p)-1))
        if inc or dec:
            count += 1
            
    return count

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
        
    root = build_tree(vals)
    print(count_monotonic_paths(root))

solve()

