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

def check_leaf_siblings(root):
    if not root:
        return True
    q = deque([root])
    while q:
        node = q.popleft()
        if node.left or node.right:
            if not (node.left and node.right):
                # If it has only one child, that child is a leaf without sibling?
                # No, the child might have children.
                # The condition is "every leaf has a sibling".
                # A leaf is a node with no children.
                # If a node has only one child, that child is a leaf only if it has no children.
                # But even if it's not a leaf, the structure is weird.
                # Actually, if a node has 1 child, that child is a leaf IF it has no children.
                # Does that leaf have a sibling? No.
                # So if any node has exactly 1 child, we must check if that child is a leaf.
                # If that child is NOT a leaf, it's fine for now, but its descendants might be leaves without siblings.
                # Actually, simpler: Just check all leaves.
                pass
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
        
    # Better approach: Collect all leaves and check if their parent has another child.
    leaves = []
    q = deque([(root, None, False)]) # node, parent, is_left
    while q:
        node, parent, is_left = q.popleft()
        if not node.left and not node.right:
            leaves.append((node, parent, is_left))
        if node.left: q.append((node.left, node, True))
        if node.right: q.append((node.right, node, False))
        
    for leaf, parent, is_left in leaves:
        if not parent: # Root is leaf
            continue # Root has no sibling, but is it required? Usually yes.
        if is_left:
            if not parent.right:
                return False
        else:
            if not parent.left:
                return False
    return True

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
    print("YES" if check_leaf_siblings(root) else "NO")

solve()

