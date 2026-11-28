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

def max_width(root):
    if not root:
        return 0
    from collections import deque
    q = deque([(root, 0)])
    max_w = 0
    while q:
        size = len(q)
        first_idx = q[0][1]
        last_idx = q[-1][1]
        max_w = max(max_w, last_idx - first_idx + 1)
        for _ in range(size):
            node, idx = q.popleft()
            norm_idx = idx - first_idx
            if node.left:
                q.append((node.left, 2 * norm_idx))
            if node.right:
                q.append((node.right, 2 * norm_idx + 1))
    return max_w

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
    print(max_width(root))

solve()

