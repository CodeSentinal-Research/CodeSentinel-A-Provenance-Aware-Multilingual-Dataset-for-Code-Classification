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

def largest_perfect_bst_size(root):
    # Returns (size, is_bst, is_perfect, min_val, max_val, height)
    if not root:
        return 0, True, True, float('inf'), float('-inf'), -1
        
    l_size, l_is_bst, l_is_perfect, l_min, l_max, l_h = largest_perfect_bst_size(root.left)
    r_size, r_is_bst, r_is_perfect, r_min, r_max, r_h = largest_perfect_bst_size(root.right)
    
    is_bst = l_is_bst and r_is_bst and l_max < root.val < r_min
    is_perfect = l_is_perfect and r_is_perfect and l_h == r_h
    
    if is_bst and is_perfect:
        size = 1 + l_size + r_size
        h = 1 + l_h
        return size, True, True, min(l_min, root.val), max(r_max, root.val), h
    else:
        return max(l_size, r_size), False, False, 0, 0, 0

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
    size, _, _, _, _, _ = largest_perfect_bst_size(root)
    print(size)

solve()

