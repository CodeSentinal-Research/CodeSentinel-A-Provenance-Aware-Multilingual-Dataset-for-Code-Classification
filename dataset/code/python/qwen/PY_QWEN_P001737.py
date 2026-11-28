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

def largest_perfect_subtree(node):
    if not node:
        return 0, 0, True # size, height, is_perfect
    ls, lh, lp = largest_perfect_subtree(node.left)
    rs, rh, rp = largest_perfect_subtree(node.right)
    
    if lp and rp and lh == rh:
        size = ls + rs + 1
        return size, lh + 1, True
    else:
        return max(ls, rs), max(lh, rh), False

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
    size, _, _ = largest_perfect_subtree(root)
    print(size)

solve()

