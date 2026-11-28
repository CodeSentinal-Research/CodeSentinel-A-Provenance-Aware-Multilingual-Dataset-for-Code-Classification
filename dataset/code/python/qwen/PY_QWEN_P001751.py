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

def count_descendants(node):
    if not node:
        return 0
    return 1 + count_descendants(node.left) + count_descendants(node.right)

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
        
    k = int(input_data[idx]); idx += 1
    
    root = build_tree(vals)
    
    def count_k_descendants(node):
        if not node:
            return 0
        desc = count_descendants(node) - 1 # Exclude self
        count = 0
        if desc == k:
            count = 1
        count += count_k_descendants(node.left)
        count += count_k_descendants(node.right)
        return count
        
    print(count_k_descendants(root))

solve()

