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

def sum_deepest_level(root):
    if not root:
        return 0
    q = deque([root])
    last_level_sum = 0
    while q:
        size = len(q)
        current_sum = 0
        for _ in range(size):
            node = q.popleft()
            current_sum += node.val
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        last_level_sum = current_sum
    return last_level_sum

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
    print(sum_deepest_level(root))

solve()

