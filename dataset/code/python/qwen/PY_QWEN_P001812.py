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

def find_keys_in_range(root, low, high):
    res = []
    def inorder(node):
        if not node:
            return
        if node.val > low:
            inorder(node.left)
        if low <= node.val <= high:
            res.append(node.val)
        if node.val < high:
            inorder(node.right)
    inorder(root)
    return res

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
        
    low = int(input_data[idx]); idx += 1
    high = int(input_data[idx])
    
    root = build_tree(vals)
    keys = find_keys_in_range(root, low, high)
    print(*keys)

solve()

