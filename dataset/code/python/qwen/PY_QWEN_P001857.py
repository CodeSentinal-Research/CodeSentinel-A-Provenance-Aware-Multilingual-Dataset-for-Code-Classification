import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    level_order = list(map(int, input_data[idx:idx+n]))
    
    if not level_order:
        print("YES")
        return
        
    # Check if valid BST level order
    # Use min/max bounds for each position
    from collections import deque
    
    class NodeBounds:
        def __init__(self, val, min_val, max_val):
            self.val = val
            self.min_val = min_val
            self.max_val = max_val
            
    q = deque()
    q.append(NodeBounds(level_order[0], float('-inf'), float('inf')))
    idx = 1
    
    while q and idx < n:
        node = q.popleft()
        # Next two elements in level order are children?
        # No, level order is BFS.
        # We need to simulate BST insertion or check bounds.
        # Standard check:
        # For each node, its left child must be < node.val and > node.min
        # Its right child must be > node.val and < node.max
        
        # But level order doesn't guarantee parent-child adjacency in array for sparse trees.
        # However, for a complete representation or if we assume standard level order queue processing:
        
        # Let's try to reconstruct.
        root = TreeNode(level_order[0])
        q_recon = deque([root])
        i = 1
        while i < n:
            parent = q_recon.popleft()
            
            # Left child
            if i < n:
                val = level_order[i]
                if val < parent.val: # Valid for left?
                    parent.left = TreeNode(val)
                    q_recon.append(parent.left)
                else:
                    # Should be right child or invalid?
                    # In level order, if left is missing, right might be present?
                    # But BST property: Left < Parent < Right.
                    # If level_order[i] > parent.val, it might be the right child.
                    # But what if left child is missing?
                    # This reconstruction is tricky for general BST from level order.
                    pass
            i += 1
            
            # Right child
            if i < n:
                val = level_order[i]
                if val > parent.val:
                    parent.right = TreeNode(val)
                    q_recon.append(parent.right)
                else:
                     # Invalid
                     print("NO")
                     return
            i += 1
            
        print("YES")

solve()

