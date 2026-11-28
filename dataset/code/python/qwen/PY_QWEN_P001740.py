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

def iterative_remove_leaves(root):
    if not root:
        return
    while root:
        leaves = []
        q = deque([(root, None, False)]) # node, parent, is_left
        has_children = False
        while q:
            node, parent, is_left = q.popleft()
            if not node.left and not node.right:
                leaves.append((node, parent, is_left))
            else:
                has_children = True
                if node.left: q.append((node.left, node, True))
                if node.right: q.append((node.right, node, False))
                
        if not has_children:
            break
            
        for node, parent, is_left in leaves:
            if parent:
                if is_left:
                    parent.left = None
                else:
                    parent.right = None
                    
        print(" ".join(str(n.val) for n, _, _ in leaves))
        if not has_children:
            break

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
    iterative_remove_leaves(root)

solve()

