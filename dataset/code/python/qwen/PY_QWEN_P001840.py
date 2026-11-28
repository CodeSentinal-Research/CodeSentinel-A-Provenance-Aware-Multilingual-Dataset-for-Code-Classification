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

def serialize_bst(root):
    def preorder(node):
        if not node:
            return []
        return [str(node.val)] + preorder(node.left) + preorder(node.right)
    return " ".join(preorder(root))

def deserialize_bst(data):
    if not data:
        return None
    vals = list(map(int, data.split()))
    root = None
    for v in vals:
        if not root:
            root = TreeNode(v)
        else:
            curr = root
            while True:
                if v < curr.val:
                    if not curr.left:
                        curr.left = TreeNode(v)
                        break
                    curr = curr.left
                else:
                    if not curr.right:
                        curr.right = TreeNode(v)
                        break
                    curr = curr.right
    return root

def level_order(root):
    if not root:
        return []
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
        
    root = build_tree(vals)
    serialized = serialize_bst(root)
    print(serialized)
    reconstructed = deserialize_bst(serialized)
    print(level_order(reconstructed))

solve()

