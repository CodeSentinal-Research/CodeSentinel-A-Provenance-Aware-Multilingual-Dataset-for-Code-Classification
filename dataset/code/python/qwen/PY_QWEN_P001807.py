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

def split_bst(root, key):
    if not root:
        return None, None
    if root.val <= key:
        left_subtree, right_subtree = split_bst(root.right, key)
        root.right = left_subtree
        return root, right_subtree
    else:
        left_subtree, right_subtree = split_bst(root.left, key)
        root.left = right_subtree
        return left_subtree, root

def level_order(root):
    if not root:
        return ""
    from collections import deque
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    return " ".join(res)

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
        
    key = int(input_data[idx])
    
    root = build_tree(vals)
    t1, t2 = split_bst(root, key)
    print(level_order(t1))
    print(level_order(t2))

solve()

