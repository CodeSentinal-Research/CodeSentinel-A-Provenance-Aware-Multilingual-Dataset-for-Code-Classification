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

def longest_decreasing_path(root):
    best_path = []
    
    def helper(node, path):
        nonlocal best_path
        if not node:
            return
        path.append(node.val)
        if not node.left and not node.right:
            if len(path) > len(best_path):
                if all(path[i] > path[i+1] for i in range(len(path)-1)):
                    best_path = path[:]
        helper(node.left, path)
        helper(node.right, path)
        path.pop()
        
    helper(root, [])
    return best_path

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
    path = longest_decreasing_path(root)
    if path:
        print(*path)
    else:
        print("")

solve()

