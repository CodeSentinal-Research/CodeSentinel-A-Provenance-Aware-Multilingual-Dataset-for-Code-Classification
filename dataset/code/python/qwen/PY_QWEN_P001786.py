import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_bst(vals):
    if not vals:
        return None
    root = TreeNode(vals[0])
    for v in vals[1:]:
        node = root
        while True:
            if v < node.val:
                if not node.left:
                    node.left = TreeNode(v)
                    break
                node = node.left
            else:
                if not node.right:
                    node.right = TreeNode(v)
                    break
                node = node.right
    return root

def search_bst(root, key):
    curr = root
    while curr:
        if curr.val == key:
            return True
        elif key < curr.val:
            curr = curr.left
        else:
            curr = curr.right
    return False

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    # Assuming input describes BST structure or insertion order? 
    # "Next N lines describe the BST". Usually level order.
    # But searching is easier if we just build it.
    # Let's assume level order input for consistency.
    vals = []
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    root = build_tree(vals) # Using generic build_tree for level order
    key = int(input_data[idx])
    
    # Search in BST property way? Or just search tree?
    # Problem says "Binary Search Tree".
    # If input is level order of BST, we can search efficiently.
    print("YES" if search_bst(root, key) else "NO")

solve()

