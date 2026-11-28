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

def is_subtree(main, sub):
    def is_same(t1, t2):
        if not t1 and not t2:
            return True
        if not t1 or not t2:
            return False
        return t1.val == t2.val and is_same(t1.left, t2.left) and is_same(t1.right, t2.right)
        
    if not main:
        return False
    if is_same(main, sub):
        return True
    return is_subtree(main.left, sub) or is_subtree(main.right, sub)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n1 = int(input_data[idx]); idx += 1
    vals1 = []
    for _ in range(n1):
        v = int(input_data[idx]); idx += 1
        vals1.append(v if v != -1 else None)
        
    n2 = int(input_data[idx]); idx += 1
    vals2 = []
    for _ in range(n2):
        v = int(input_data[idx]); idx += 1
        vals2.append(v if v != -1 else None)
        
    t1 = build_tree(vals1)
    t2 = build_tree(vals2)
    
    print("YES" if is_subtree(t1, t2) else "NO")

solve()

