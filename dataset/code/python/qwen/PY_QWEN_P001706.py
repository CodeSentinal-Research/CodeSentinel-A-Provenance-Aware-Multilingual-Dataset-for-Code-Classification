import sys
from collections import deque

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

def count_complete_nodes(root):
    if not root:
        return 0
    
    def get_left_height(node):
        h = 0
        while node:
            h += 1
            node = node.left
        return h
        
    def get_right_height(node):
        h = 0
        while node:
            h += 1
            node = node.right
        return h
        
    lh = get_left_height(root)
    rh = get_right_height(root)
    
    if lh == rh:
        return (1 << lh) - 1
    else:
        return 1 + count_complete_nodes(root.left) + count_complete_nodes(root.right)

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
    print(count_complete_nodes(root))

solve()

