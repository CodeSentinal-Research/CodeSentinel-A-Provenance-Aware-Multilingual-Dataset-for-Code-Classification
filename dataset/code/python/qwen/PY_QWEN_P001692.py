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

def longest_consecutive(node):
    if not node:
        return 0
    left_len = longest_consecutive(node.left)
    right_len = longest_consecutive(node.right)
    
    curr_len = 1
    if node.left and node.left.val == node.val + 1:
        curr_len = max(curr_len, left_len + 1)
    if node.right and node.right.val == node.val + 1:
        curr_len = max(curr_len, right_len + 1)
        
    global_max[0] = max(global_max[0], curr_len)
    return curr_len

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
        
    global global_max
    global_max = [0]
    
    root = build_tree(vals)
    longest_consecutive(root)
    print(global_max[0])

solve()

