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

def max_ancestor_diff(node, min_val, max_val):
    if not node:
        return 0
    diff = max(abs(node.val - min_val), abs(node.val - max_val))
    new_min = min(min_val, node.val)
    new_max = max(max_val, node.val)
    left_diff = max_ancestor_diff(node.left, new_min, new_max)
    right_diff = max_ancestor_diff(node.right, new_min, new_max)
    return max(diff, left_diff, right_diff)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    # Skip values line? Assuming level order next.
    vals = []
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    root = build_tree(vals)
    if not root:
        print(0)
    else:
        print(max_ancestor_diff(root, root.val, root.val))

solve()

