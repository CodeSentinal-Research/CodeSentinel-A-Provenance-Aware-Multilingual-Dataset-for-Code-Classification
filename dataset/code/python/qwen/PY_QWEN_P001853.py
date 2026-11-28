import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    preorder = list(map(int, input_data[idx:idx+n]))
    
    if n <= 1:
        print("YES")
        return
        
    # Check if every internal node has exactly one child
    # This implies the tree is a path.
    # In preorder of a BST, if it's a path, the sequence is either strictly increasing or decreasing?
    # No.
    # A node has exactly one child if it has either a left or a right child, but not both.
    # We can reconstruct or check properties.
    # Simpler: Count nodes with 2 children. If 0, then YES (assuming N>1 implies internal nodes exist).
    # Actually, leaf nodes have 0 children. Internal nodes must have 1.
    
    # Reconstruct BST from preorder
    stack = []
    root = TreeNode(preorder[0])
    stack.append(root)
    
    for i in range(1, n):
        val = preorder[i]
        node = TreeNode(val)
        parent = None
        while stack and val > stack[-1].val:
            parent = stack.pop()
        if parent:
            parent.right = node
        else:
            stack[-1].left = node
        stack.append(node)
        
    # Check property
    q = deque([root])
    valid = True
    while q:
        node = q.popleft()
        has_left = node.left is not None
        has_right = node.right is not None
        if has_left and has_right:
            valid = False
            break
        if has_left: q.append(node.left)
        if has_right: q.append(node.right)
        
    print("YES" if valid else "NO")

solve()

