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

def max_independent_set(root):
    def helper(node):
        if not node:
            return 0, 0 # include, exclude
        inc_l, exc_l = helper(node.left)
        inc_r, exc_r = helper(node.right)
        
        include = 1 + exc_l + exc_r
        exclude = max(inc_l, exc_l) + max(inc_r, exc_r)
        
        return include, exclude
        
    inc, exc = helper(root)
    return max(inc, exc)

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
    print(max_independent_set(root))

solve()

