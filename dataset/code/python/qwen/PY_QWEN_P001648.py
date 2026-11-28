import sys
from collections import deque

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

def serialize(root):
    if not root:
        return "#"
    return str(root.val) + "," + serialize(root.left) + "," + serialize(root.right)

def deserialize(data):
    vals = iter(data.split(','))
    def helper():
        val = next(vals)
        if val == '#':
            return None
        node = TreeNode(int(val))
        node.left = helper()
        node.right = helper()
        return node
    return helper()

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    if n == 0:
        print("#")
        return
    vals = []
    idx = 1
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    root = build_tree(vals)
    s = serialize(root)
    print(s)
    # Reconstruct to verify? Problem asks to print serialized and reconstructed.
    # Reconstructed tree in required traversal format (e.g. level order)
    new_root = deserialize(s)
    # Print level order of new_root
    if not new_root:
        print("")
    else:
        q = deque([new_root])
        res = []
        while q:
            node = q.popleft()
            res.append(str(node.val))
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        print(" ".join(res))

solve()

