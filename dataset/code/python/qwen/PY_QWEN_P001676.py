import sys
from collections import defaultdict, deque

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

def anti_diagonal_traversal(root):
    if not root:
        return []
    map_diag = defaultdict(list)
    q = deque([(root, 0)])
    while q:
        node, d = q.popleft()
        map_diag[d].append(node.val)
        if node.right:
            q.append((node.right, d + 1))
        if node.left:
            q.append((node.left, d))
            
    result = []
    for d in sorted(map_diag.keys()):
        result.extend(map_diag[d])
    return result

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
    print(*anti_diagonal_traversal(root))

solve()

