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

def insert_level(root, val, depth):
    if not root:
        return None
    if depth == 1:
        new_left = TreeNode(val)
        new_right = TreeNode(val)
        new_left.left = root.left
        new_right.right = root.right
        root.left = new_left
        root.right = new_right
    else:
        root.left = insert_level(root.left, val, depth - 1)
        root.right = insert_level(root.right, val, depth - 1)
    return root

def level_order(root):
    if not root:
        return []
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    return " ".join(res)

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
        
    x = int(input_data[idx]); idx += 1
    d = int(input_data[idx]); idx += 1
    
    root = build_tree(vals)
    if d == 1:
        new_root = TreeNode(x)
        new_root.left = root
        root = new_root
    else:
        root = insert_level(root, x, d - 1)
        
    print(level_order(root))

solve()

