import sys
sys.setrecursionlimit(500000)
from collections import defaultdict

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

def find_duplicates(node, counter, roots):
    if not node:
        return "#"
    serial = str(node.val) + "," + find_duplicates(node.left, counter, roots) + "," + find_duplicates(node.right, counter, roots)
    counter[serial] += 1
    if counter[serial] == 2:
        roots.append(node.val)
    return serial

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
    counter = defaultdict(int)
    roots = []
    find_duplicates(root, counter, roots)
    
    if roots:
        print(*sorted(roots))
    else:
        print("NONE")

solve()

