import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    level_order = list(map(int, input_data[idx:idx+n]))
    
    if not level_order:
        print("")
        return
        
    root = TreeNode(level_order[0])
    q = deque([root])
    i = 1
    
    while i < n:
        parent = q.popleft()
        
        # Find left child: first element in remaining list that is < parent.val
        # Find right child: first element in remaining list that is > parent.val
        # But level order processes level by level.
        
        # Correct algorithm for BST from Level Order:
        # Maintain a queue of nodes with their valid ranges.
        
        # Simplified:
        # Insert nodes one by one from level order into BST.
        # Since level order visits parents before children, inserting them in order
        # into an empty BST will reconstruct the original BST.
        
        def insert_bst(root, val):
            if not root:
                return TreeNode(val)
            if val < root.val:
                root.left = insert_bst(root.left, val)
            else:
                root.right = insert_bst(root.right, val)
            return root
            
        for i in range(1, n):
            root = insert_bst(root, level_order[i])
            
        # Print reconstructed tree (e.g., inorder)
        def inorder(node):
            if not node:
                return []
            return inorder(node.left) + [str(node.val)] + inorder(node.right)
            
        print(" ".join(inorder(root)))

solve()

