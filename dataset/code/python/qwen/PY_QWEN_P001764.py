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

def largest_univalue_subtree_size(root):
    max_size = 0
    
    def helper(node):
        nonlocal max_size
        if not node:
            return 0, True, None
        left_size, left_uni, left_val = helper(node.left)
        right_size, right_uni, right_val = helper(node.right)
        
        is_uni = True
        if not left_uni or (left_val is not None and left_val != node.val):
            is_uni = False
        if not right_uni or (right_val is not None and right_val != node.val):
            is_uni = False
            
        if is_uni:
            size = 1 + left_size + right_size
            max_size = max(max_size, size)
            return size, True, node.val
        return 0, False, None
        
    helper(root)
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
    print(largest_univalue_subtree_size(root))

solve()

