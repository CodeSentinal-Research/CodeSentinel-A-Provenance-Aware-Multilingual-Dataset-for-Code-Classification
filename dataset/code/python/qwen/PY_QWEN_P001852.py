import sys
from math import factorial

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

def count_sequences(node):
    if not node:
        return 1, 0
    left_count, left_size = count_sequences(node.left)
    right_count, right_size = count_sequences(node.right)
    
    total_size = left_size + right_size
    # Number of ways to interleave left and right sequences
    # C(total_size, left_size) * left_count * right_count
    ways = factorial(total_size) // (factorial(left_size) * factorial(right_size))
    
    return ways * left_count * right_count, total_size + 1

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
    count, _ = count_sequences(root)
    print(count)

solve()

