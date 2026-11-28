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

def are_siblings(root, p, q):
    if not root:
        return False
    q_queue = deque([root])
    while q_queue:
        node = q_queue.popleft()
        if node.left and node.right:
            if (node.left.val == p and node.right.val == q) or \
               (node.left.val == q and node.right.val == p):
                return True
        if node.left: q_queue.append(node.left)
        if node.right: q_queue.append(node.right)
    return False

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
        
    p = int(input_data[idx]); idx += 1
    q = int(input_data[idx])
    
    root = build_tree(vals)
    print("YES" if are_siblings(root, p, q) else "NO")

solve()

