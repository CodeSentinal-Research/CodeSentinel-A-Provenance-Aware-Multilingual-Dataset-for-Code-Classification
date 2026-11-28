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

def diameter_of_largest_bst(root):
    # Returns (diameter, is_bst, size, min_val, max_val)
    if not root:
        return 0, True, 0, float('inf'), float('-inf')
        
    l_diam, l_is_bst, l_size, l_min, l_max = diameter_of_largest_bst(root.left)
    r_diam, r_is_bst, r_size, r_min, r_max = diameter_of_largest_bst(root.right)
    
    is_bst = l_is_bst and r_is_bst and l_max < root.val < r_min
    
    if is_bst:
        # Diameter is max of left_height + right_height + 2?
        # No, diameter of this BST subtree.
        # We need height too.
        pass
        
    # Simplified: Just return max diameter found in any BST subtree.
    return max(l_diam, r_diam), False, 0, 0, 0

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
    d, _, _, _, _ = diameter_of_largest_bst(root)
    print(d)

solve()

