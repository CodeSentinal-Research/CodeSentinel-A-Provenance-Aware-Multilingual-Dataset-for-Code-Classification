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

def reverse_odd_levels(root):
    if not root:
        return
    q = deque([root])
    level = 0
    while q:
        size = len(q)
        nodes_in_level = []
        for _ in range(size):
            node = q.popleft()
            nodes_in_level.append(node)
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        if level % 2 != 0:
            vals = [node.val for node in nodes_in_level]
            vals.reverse()
            for i, node in enumerate(nodes_in_level):
                node.val = vals[i]
        level += 1

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
        
    root = build_tree(vals)
    reverse_odd_levels(root)
    print(level_order(root))

solve()

