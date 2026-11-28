import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def solve():
    traversal = sys.stdin.readline().strip()
    # Format: D-D-V... where D is dashes for depth, V is value
    # Parse manually
    nodes = []
    i = 0
    while i < len(traversal):
        depth = 0
        while i < len(traversal) and traversal[i] == '-':
            depth += 1
            i += 1
        val_start = i
        while i < len(traversal) and traversal[i] != '-':
            i += 1
        val = int(traversal[val_start:i])
        nodes.append((depth, val))
        
    if not nodes:
        return
        
    root = TreeNode(nodes[0][1])
    stack = [(root, 0)]
    
    for depth, val in nodes[1:]:
        while stack[-1][1] != depth - 1:
            stack.pop()
        parent = stack[-1][0]
        if not parent.left:
            parent.left = TreeNode(val)
            stack.append((parent.left, depth))
        else:
            parent.right = TreeNode(val)
            stack.append((parent.right, depth))
            
    # Print level order
    from collections import deque
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    print(" ".join(res))

solve()

