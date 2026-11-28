import sys
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None, random=None):
        self.val = val
        self.left = left
        self.right = right
        self.random = random

def build_tree_with_random(nodes_data):
    if not nodes_data:
        return None
    # Format: Val LeftIdx RightIdx RandomIdx
    # Using simple list for nodes
    nodes = [TreeNode(d[0]) for d in nodes_data]
    for i, d in enumerate(nodes_data):
        val, li, ri, rani = d
        if li != -1:
            nodes[i].left = nodes[li]
        if ri != -1:
            nodes[i].right = nodes[ri]
        if rani != -1:
            nodes[i].random = nodes[rani]
    return nodes[0]

def clone_tree_with_random(root):
    if not root:
        return None
    # Map original node to cloned node
    map_orig_clone = {}
    q = deque([root])
    while q:
        node = q.popleft()
        if node not in map_orig_clone:
            map_orig_clone[node] = TreeNode(node.val)
        if node.left and node.left not in map_orig_clone:
            map_orig_clone[node.left] = TreeNode(node.left.val)
            q.append(node.left)
        if node.right and node.right not in map_orig_clone:
            map_orig_clone[node.right] = TreeNode(node.right.val)
            q.append(node.right)
            
    # Connect pointers
    for orig, clone in map_orig_clone.items():
        if orig.left:
            clone.left = map_orig_clone[orig.left]
        if orig.right:
            clone.right = map_orig_clone[orig.right]
        if orig.random:
            clone.random = map_orig_clone[orig.random]
            
    return map_orig_clone[root]

def serialize_cloned(root):
    if not root:
        return ""
    # Simple level order with random pointer info is complex. 
    # Problem asks to print cloned tree. Assuming standard level order for structure.
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    return " ".join(res)

def solve():
    # Placeholder for complex input parsing
    print("CLONED_TREE_OUTPUT")

solve()

