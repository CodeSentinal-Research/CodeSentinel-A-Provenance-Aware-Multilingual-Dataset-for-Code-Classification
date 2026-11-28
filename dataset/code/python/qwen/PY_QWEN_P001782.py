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

def largest_symmetric_subtree_size(root):
    max_size = 0
    
    def size(node):
        if not node:
            return 0
        return 1 + size(node.left) + size(node.right)
        
    def is_symmetric(t1, t2):
        if not t1 and not t2:
            return True
        if not t1 or not t2:
            return False
        return t1.val == t2.val and is_symmetric(t1.left, t2.right) and is_symmetric(t1.right, t2.left)
        
    def check_all(node):
        nonlocal max_size
        if not node:
            return
        if is_symmetric(node.left, node.right):
            s = 1 + size(node.left) + size(node.right)
            max_size = max(max_size, s)
        check_all(node.left)
        check_all(node.right)
        
    check_all(root)
    return max_size

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
    print(largest_symmetric_subtree_size(root))

solve()

