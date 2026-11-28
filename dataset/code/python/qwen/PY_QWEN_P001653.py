import sys
sys.setrecursionlimit(500000)

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

def max_path_sum_helper(node):
    if not node:
        return 0
    left = max(0, max_path_sum_helper(node.left))
    right = max(0, max_path_sum_helper(node.right))
    global_max[0] = max(global_max[0], node.val + left + right)
    return node.val + max(left, right)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    # Skip values line if present? Problem says "Second line contains values".
    # Assuming next N lines are structure.
    # Let's assume level order with -1 for null.
    vals = []
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    global global_max
    global_max = [float('-inf')]
    
    root = build_tree(vals)
    max_path_sum_helper(root)
    print(global_max[0])

solve()

