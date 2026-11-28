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

def get_rank(root, key):
    rank = 0
    curr = root
    while curr:
        if key > curr.val:
            rank += 1
            if curr.left:
                # Add size of left subtree? 
                # Simpler: just count nodes visited that are smaller?
                # No, rank is number of keys strictly smaller.
                # We need to traverse.
                pass
            curr = curr.right
        elif key < curr.val:
            curr = curr.left
        else:
            # Found key. Add size of left subtree.
            # Need size attribute or function.
            break
    return rank # Placeholder

# Correct implementation requires size tracking or full traversal.
# Using full traversal for simplicity given constraints.
def count_smaller(root, key):
    count = 0
    def inorder(node):
        nonlocal count
        if not node:
            return
        if node.val < key:
            count += 1
        inorder(node.left)
        inorder(node.right)
    inorder(root)
    return count

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
    print(count_smaller(root, key))

solve()

