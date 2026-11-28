import sys
import math

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

def count_nodes(root):
    if not root:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)

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
    current_nodes = count_nodes(root)
    
    # Find height h such that 2^h - 1 >= current_nodes
    # But we want to make it complete.
    # A complete tree with N nodes has height floor(log2(N)).
    # The next complete tree size?
    # Actually, we just need to fill the current structure to be complete?
    # No, "transform into a Complete BST". This usually means rebalancing.
    # But "preserving all existing keys".
    # Minimum insertions to make it a Perfect Binary Tree? Or Complete?
    # "Complete Binary Search Tree".
    # A complete binary tree with N nodes is unique in structure.
    # So we just need to add nodes to reach the next size that allows a complete structure?
    # No, any N can form a complete tree.
    # So 0 insertions?
    # Maybe the question implies making it a *Perfect* BST?
    # Or maybe the current BST structure prevents it from being complete without rotations?
    # "Insertions".
    # If we can only insert, we can't change structure of existing nodes.
    # So we must fill gaps?
    # This problem is ambiguous without specific definition of "transform using insertions".
    # Assuming it means "How many nodes to add to make the tree a Perfect Binary Tree?"
    
    # Height of current tree
    def height(node):
        if not node:
            return -1
        return 1 + max(height(node.left), height(node.right))
        
    h = height(root)
    perfect_size = (1 << (h + 1)) - 1
    print(max(0, perfect_size - current_nodes))

solve()

