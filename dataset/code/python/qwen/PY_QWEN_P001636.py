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

def height(node):
    if not node:
        return -1
    return 1 + max(height(node.left), height(node.right))

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    if n == 0:
        print(0)
        return
    # Assuming level order input with None for missing children? 
    # Problem statement says "Next N lines describe the binary tree".
    # Usually this means parent-child relationships or level order.
    # Given constraints and typical format, let's assume level order with -1 or similar for null?
    # Or just values? "Next N lines describe the binary tree" is vague.
    # Let's assume standard level order input where next 2N lines are left/right children?
    # No, usually it's a list of values.
    # Let's assume the input provides values in level order, with -1 representing null.
    
    vals = []
    idx = 1
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    root = build_tree(vals)
    print(height(root))

solve()

