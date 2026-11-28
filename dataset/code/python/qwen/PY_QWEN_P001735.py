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

def is_mirror_subtree(main, mirror):
    if not main and not mirror:
        return True
    if not main or not mirror:
        return False
    if main.val != mirror.val:
        return False
    return is_mirror_subtree(main.left, mirror.right) and is_mirror_subtree(main.right, mirror.left)

def check_mirror_subtree(root):
    if not root:
        return False
    # Create mirror of root
    def create_mirror(node):
        if not node:
            return None
        m = TreeNode(node.val)
        m.left = create_mirror(node.right)
        m.right = create_mirror(node.left)
        return m
    mirror_root = create_mirror(root)
    
    # Check if mirror_root is subtree of root
    def is_subtree(s, t):
        if not t:
            return True
        if not s:
            return False
        if is_mirror_subtree(s, t):
            return True
        return is_subtree(s.left, t) or is_subtree(s.right, t)
        
    return is_subtree(root, mirror_root)

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
    print("YES" if check_mirror_subtree(root) else "NO")

solve()

