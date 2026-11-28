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

def find_cousins(root, target):
    if not root:
        return []
    q = deque([(root, None, 0)]) # node, parent, depth
    target_depth = -1
    target_parent = None
    
    while q:
        node, parent, depth = q.popleft()
        if node.val == target:
            target_depth = depth
            target_parent = parent
            break
        if node.left: q.append((node.left, node, depth + 1))
        if node.right: q.append((node.right, node, depth + 1))
        
    if target_depth == -1:
        return []
        
    cousins = []
    q = deque([(root, None, 0)])
    while q:
        node, parent, depth = q.popleft()
        if depth == target_depth:
            if parent != target_parent:
                cousins.append(node.val)
        elif depth > target_depth:
            break
        if node.left: q.append((node.left, node, depth + 1))
        if node.right: q.append((node.right, node, depth + 1))
        
    return sorted(cousins)

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
        
    target = int(input_data[idx])
    
    root = build_tree(vals)
    res = find_cousins(root, target)
    if res:
        print(*res)
    else:
        print("NONE")

solve()

