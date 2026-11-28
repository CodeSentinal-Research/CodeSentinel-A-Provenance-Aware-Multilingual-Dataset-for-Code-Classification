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

def min_cameras(node):
    if not node:
        return 1 # Covered
    left = min_cameras(node.left)
    right = min_cameras(node.right)
    
    if left == 0 or right == 0:
        cameras[0] += 1
        return 2 # Has camera
    if left == 2 or right == 2:
        return 1 # Covered
    return 0 # Needs coverage

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    if n == 0:
        print(0)
        return
    vals = []
    idx = 1
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    global cameras
    cameras = [0]
    
    root = build_tree(vals)
    status = min_cameras(root)
    if status == 0:
        cameras[0] += 1
        
    print(cameras[0])

solve()

