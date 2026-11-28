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

def longest_alternating_even_odd(root):
    max_len = 0
    
    def helper(node, prev_parity, length):
        nonlocal max_len
        if not node:
            return
        curr_parity = node.val % 2
        if prev_parity is None or curr_parity != prev_parity:
            length += 1
        else:
            length = 1
        max_len = max(max_len, length)
        helper(node.left, curr_parity, length)
        helper(node.right, curr_parity, length)
        
    helper(root, None, 0)
    return max_len

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
    print(longest_alternating_even_odd(root))

solve()

