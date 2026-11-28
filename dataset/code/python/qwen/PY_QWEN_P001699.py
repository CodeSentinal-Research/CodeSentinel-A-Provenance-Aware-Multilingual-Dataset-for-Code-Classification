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

def is_even_odd(root):
    if not root:
        return True
    q = deque([(root, 0)])
    while q:
        size = len(q)
        prev_val = None
        for i in range(size):
            node, level = q.popleft()
            if level % 2 == 0: # Even level -> Odd values, Strictly Increasing
                if node.val % 2 == 0:
                    return False
                if prev_val is not None and node.val <= prev_val:
                    return False
            else: # Odd level -> Even values, Strictly Decreasing
                if node.val % 2 != 0:
                    return False
                if prev_val is not None and node.val >= prev_val:
                    return False
            prev_val = node.val
            if node.left: q.append((node.left, level + 1))
            if node.right: q.append((node.right, level + 1))
    return True

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
    print("YES" if is_even_odd(root) else "NO")

solve()

