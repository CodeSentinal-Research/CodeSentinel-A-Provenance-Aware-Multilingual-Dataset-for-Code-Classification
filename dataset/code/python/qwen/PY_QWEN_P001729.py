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

def lca(root, p, q):
    if not root or root.val == p or root.val == q:
        return root
    left = lca(root.left, p, q)
    right = lca(root.right, p, q)
    if left and right:
        return root
    return left if left else right

def distance(root, val):
    if not root:
        return -1
    if root.val == val:
        return 0
    left = distance(root.left, val)
    if left != -1:
        return left + 1
    right = distance(root.right, val)
    if right != -1:
        return right + 1
    return -1

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
        
    u = int(input_data[idx]); idx += 1
    v = int(input_data[idx]); idx += 1
    
    root = build_tree(vals)
    ancestor = lca(root, u, v)
    if not ancestor:
        print(-1)
    else:
        d1 = distance(ancestor, u)
        d2 = distance(ancestor, v)
        print(d1 + d2)

solve()

