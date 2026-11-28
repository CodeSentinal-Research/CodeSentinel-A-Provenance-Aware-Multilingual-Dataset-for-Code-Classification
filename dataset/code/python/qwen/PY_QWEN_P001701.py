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

def replace_with_cousin_sum(root):
    if not root:
        return
    q = deque([(root, None)]) # node, parent
    while q:
        size = len(q)
        level_nodes = []
        for _ in range(size):
            node, parent = q.popleft()
            level_nodes.append((node, parent))
            if node.left: q.append((node.left, node))
            if node.right: q.append((node.right, node))
            
        # Calculate sum of children for each parent in this level's parents (which are in previous level)
        # Actually, cousin sum for a node is Total Level Sum - Node Value - Sibling Value
        
        total_level_sum = sum(node.val for node, _ in level_nodes)
        
        # Group by parent to find sibling sums
        parent_child_sum = {}
        for node, parent in level_nodes:
            if parent:
                parent_child_sum[parent] = parent_child_sum.get(parent, 0) + node.val
                
        for node, parent in level_nodes:
            sibling_sum = 0
            if parent:
                sibling_sum = parent_child_sum[parent] - node.val
            
            # Cousin sum = Total Level Sum - (Node + Siblings)
            # Note: Root has no cousins, sum is 0.
            if node == root:
                node.val = 0
            else:
                node.val = total_level_sum - (node.val + sibling_sum)

def level_order(root):
    if not root:
        return []
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
    replace_with_cousin_sum(root)
    print(level_order(root))

solve()

