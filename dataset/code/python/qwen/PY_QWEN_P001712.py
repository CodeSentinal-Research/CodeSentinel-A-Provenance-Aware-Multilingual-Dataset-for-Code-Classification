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

def convert_to_children_sum(node):
    if not node:
        return 0
    if not node.left and not node.right:
        return node.val
        
    left_sum = convert_to_children_sum(node.left)
    right_sum = convert_to_children_sum(node.right)
    
    total = left_sum + right_sum
    diff = total - node.val
    
    if diff > 0:
        node.val += diff
    elif diff < 0:
        # Increment one child to satisfy property
        if node.left:
            node.left.val -= diff
        elif node.right:
            node.right.val -= diff
            
    return node.val

def level_order(root):
    if not root:
        return []
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    return " ".join(res)

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
    convert_to_children_sum(root)
    from collections import deque
    print(level_order(root))

solve()

