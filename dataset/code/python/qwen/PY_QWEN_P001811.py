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

def largest_bst_size(root):
    max_size = [0]
    
    def helper(node):
        if not node:
            return True, 0, float('inf'), float('-inf')
        
        left_is_bst, left_size, left_min, left_max = helper(node.left)
        right_is_bst, right_size, right_min, right_max = helper(node.right)
        
        if left_is_bst and right_is_bst and left_max < node.val < right_min:
            size = 1 + left_size + right_size
            max_size[0] = max(max_size[0], size)
            return True, size, min(left_min, node.val), max(right_max, node.val)
        else:
            return False, 0, 0, 0
            
    helper(root)
    return max_size[0]

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
    print(largest_bst_size(root))

solve()

