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

def max_product_split(node):
    if not node:
        return 0
    left_sum = max_product_split(node.left)
    right_sum = max_product_split(node.right)
    total = left_sum + right_sum + node.val
    subtree_sums.append(total)
    return total

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
        
    global subtree_sums
    subtree_sums = []
    
    root = build_tree(vals)
    total_sum = max_product_split(root)
    
    max_prod = 0
    for s in subtree_sums:
        if s != total_sum:
            prod = s * (total_sum - s)
            max_prod = max(max_prod, prod)
            
    print(max_prod)

solve()

