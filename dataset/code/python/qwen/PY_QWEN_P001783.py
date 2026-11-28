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

def find_centroid(root):
    # Calculate subtree sizes
    sizes = {}
    def calc_size(node):
        if not node:
            return 0
        s = 1 + calc_size(node.left) + calc_size(node.right)
        sizes[id(node)] = s
        return s
        
    total = calc_size(root)
    
    # Find centroid
    def find(node):
        if not node:
            return None
        for child in [node.left, node.right]:
            if child and sizes[id(child)] > total // 2:
                return find(child)
        return node
        
    centroid = find(root)
    return centroid.val if centroid else None

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
    print(find_centroid(root))

solve()

