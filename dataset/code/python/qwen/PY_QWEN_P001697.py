import sys
sys.setrecursionlimit(500000)

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

def prune(node):
    if not node:
        return None
    node.left = prune(node.left)
    node.right = prune(node.right)
    if not node.left and not node.right and node.val == 0:
        return None
    return node

def level_order(root):
    if not root:
        return []
    from collections import deque
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
    root = prune(root)
    print(level_order(root))

solve()

