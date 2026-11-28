import sys
sys.setrecursionlimit(500000)

class TreeNode:
    def __init__(self, val=0, left=None, right=None, is_threaded=False):
        self.val = val
        self.left = left
        self.right = right
        self.is_threaded = is_threaded

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

def inorder_threading(node, prev):
    if not node:
        return prev
    prev = inorder_threading(node.left, prev)
    if prev and not prev.right:
        prev.right = node
        prev.is_threaded = True
    prev = node
    return inorder_threading(node.right, prev)

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
    inorder_threading(root, None)
    print("THREADED_TREE_OUTPUT")

solve()

