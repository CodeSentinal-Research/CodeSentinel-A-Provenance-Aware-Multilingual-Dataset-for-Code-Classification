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

def longest_zigzag(node):
    if not node:
        return -1, -1 # left_len, right_len
    ll, lr = longest_zigzag(node.left)
    rl, rr = longest_zigzag(node.right)
    
    left_len = lr + 1 if node.left else 0
    right_len = rl + 1 if node.right else 0
    
    global_max[0] = max(global_max[0], left_len, right_len)
    return left_len, right_len

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    if n == 0:
        print(0)
        return
    vals = []
    idx = 1
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    global global_max
    global_max = [0]
    
    root = build_tree(vals)
    longest_zigzag(root)
    print(global_max[0])

solve()

