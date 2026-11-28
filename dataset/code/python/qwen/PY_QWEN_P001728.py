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

def find_kth_ancestor(node, target, k):
    if not node:
        return None
    if node.val == target:
        return k
    left_res = find_kth_ancestor(node.left, target, k)
    if isinstance(left_res, int):
        if left_res == 0:
            return node.val
        return left_res - 1
    right_res = find_kth_ancestor(node.right, target, k)
    if isinstance(right_res, int):
        if right_res == 0:
            return node.val
        return right_res - 1
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
        
    target = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    
    root = build_tree(vals)
    res = find_kth_ancestor(root, target, k)
    print(res if res is not None else "NONE")

solve()

