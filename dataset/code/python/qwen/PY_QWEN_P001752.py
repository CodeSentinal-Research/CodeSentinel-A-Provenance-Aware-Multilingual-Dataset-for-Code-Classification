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

def print_ancestor_counts(root):
    if not root:
        return
    # BFS to assign depth/ancestors count
    from collections import deque
    q = deque([(root, 0)]) # node, depth (which is num ancestors)
    res = []
    while q:
        node, depth = q.popleft()
        res.append((node.val, depth))
        if node.left: q.append((node.left, depth + 1))
        if node.right: q.append((node.right, depth + 1))
        
    # Sort by value to match typical output requirements or just print in order? 
    # Problem says "Print the ancestor count for every node". Usually implies specific order.
    # Let's print in level order as traversed.
    print(" ".join(f"{val}:{count}" for val, count in res))

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
    print_ancestor_counts(root)

solve()

