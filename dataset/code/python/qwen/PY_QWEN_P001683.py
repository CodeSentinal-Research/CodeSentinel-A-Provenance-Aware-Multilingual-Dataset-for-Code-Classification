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

def deepest_left_leaf(root):
    if not root:
        return None
    q = deque([(root, 0, False)]) # node, depth, is_left
    max_depth = -1
    result = None
    
    while q:
        node, depth, is_left = q.popleft()
        if not node.left and not node.right:
            if is_left and depth > max_depth:
                max_depth = depth
                result = node.val
        if node.left: q.append((node.left, depth + 1, True))
        if node.right: q.append((node.right, depth + 1, False))
        
    return result

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    if n == 0:
        print("NONE")
        return
    vals = []
    idx = 1
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    root = build_tree(vals)
    res = deepest_left_leaf(root)
    print(res if res is not None else "NONE")

solve()

