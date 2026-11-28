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

def is_sum_tree(node):
    if not node or (not node.left and not node.right):
        return True, 0
    left_ok, left_sum = is_sum_tree(node.left)
    right_ok, right_sum = is_sum_tree(node.right)
    if not left_ok or not right_ok:
        return False, 0
    if node.val == left_sum + right_sum:
        return True, node.val + left_sum + right_sum
    return False, 0

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
    ok, _ = is_sum_tree(root)
    print("YES" if ok else "NO")

solve()

