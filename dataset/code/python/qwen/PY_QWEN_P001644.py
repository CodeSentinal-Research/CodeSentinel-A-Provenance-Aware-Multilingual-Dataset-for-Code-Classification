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

def boundary_traversal(root):
    if not root:
        return []
    res = []
    if root.left or root.right:
        res.append(root.val)
        
    # Left boundary
    node = root.left
    while node:
        if node.left or node.right:
            res.append(node.val)
        if node.left:
            node = node.left
        else:
            node = node.right
            
    # Leaves
    def add_leaves(node):
        if not node:
            return
        if not node.left and not node.right:
            res.append(node.val)
            return
        add_leaves(node.left)
        add_leaves(node.right)
        
    add_leaves(root.left)
    add_leaves(root.right)
    
    # Right boundary (reverse)
    stack = []
    node = root.right
    while node:
        if node.left or node.right:
            stack.append(node.val)
        if node.right:
            node = node.right
        else:
            node = node.left
            
    res.extend(stack[::-1])
    return res

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    if n == 0:
        print("")
        return
    vals = []
    idx = 1
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    root = build_tree(vals)
    print(*boundary_traversal(root))

solve()

