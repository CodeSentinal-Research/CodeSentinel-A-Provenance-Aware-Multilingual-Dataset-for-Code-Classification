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

def lca_of_multiple(root, keys):
    if not root or not keys:
        return None
    keys_set = set(keys)
    
    # Find min and max of keys
    min_key = min(keys_set)
    max_key = max(keys_set)
    
    curr = root
    while curr:
        if curr.val > max_key:
            curr = curr.left
        elif curr.val < min_key:
            curr = curr.right
        else:
            return curr.val
    return None

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
    keys = list(map(int, input_data[idx:idx+k]))
    
    root = build_tree(vals)
    print(lca_of_multiple(root, keys))

solve()

