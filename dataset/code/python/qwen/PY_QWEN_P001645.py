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

def vertical_order(root):
    if not root:
        return []
    map_cols = defaultdict(list)
    q = deque([(root, 0, 0)]) # node, col, row
    while q:
        node, col, row = q.popleft()
        map_cols[col].append((row, node.val))
        if node.left:
            q.append((node.left, col - 1, row + 1))
        if node.right:
            q.append((node.right, col + 1, row + 1))
            
    result = []
    for col in sorted(map_cols.keys()):
        nodes = sorted(map_cols[col])
        result.extend([val for _, val in nodes])
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
    print(*vertical_order(root))

solve()

