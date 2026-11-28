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

def count_univalue_subtrees(root):
    count = 0
    
    def helper(node):
        nonlocal count
        if not node:
            return True, None
        left_uni, left_val = helper(node.left)
        right_uni, right_val = helper(node.right)
        
        is_uni = True
        if not left_uni or (left_val is not None and left_val != node.val):
            is_uni = False
        if not right_uni or (right_val is not None and right_val != node.val):
            is_uni = False
            
        if is_uni:
            count += 1
            return True, node.val
        return False, None
        
    helper(root)
    return count

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
    print(count_univalue_subtrees(root))

solve()

