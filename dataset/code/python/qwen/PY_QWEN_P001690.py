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

def max_bst_sum(node):
    if not node:
        return True, float('inf'), float('-inf'), 0, 0 # is_bst, min, max, sum, max_bst_sum
        
    lb, lmin, lmax, lsum, lmax_bst = max_bst_sum(node.left)
    rb, rmin, rmax, rsum, rmax_bst = max_bst_sum(node.right)
    
    curr_sum = lsum + rsum + node.val
    
    if lb and rb and lmax < node.val < rmin:
        is_bst = True
        min_val = min(lmin, node.val)
        max_val = max(rmax, node.val)
        max_bst = max(lmax_bst, rmax_bst, curr_sum)
    else:
        is_bst = False
        min_val = 0
        max_val = 0
        max_bst = max(lmax_bst, rmax_bst)
        
    return is_bst, min_val, max_val, curr_sum, max_bst

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
    _, _, _, _, max_bst = max_bst_sum(root)
    print(max_bst)

solve()

