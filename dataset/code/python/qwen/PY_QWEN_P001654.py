import sys
sys.setrecursionlimit(500000)

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

def inorder(node, res):
    if not node:
        return
    inorder(node.left, res)
    res.append(node.val)
    inorder(node.right, res)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    if n == 0:
        print("")
        return
    vals = []
    idx = 1
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    root = build_tree(vals)
    res = []
    inorder(root, res)
    
    # Find corrupted node: should be sorted.
    # Find first inversion.
    corrupted_idx = -1
    for i in range(1, len(res)):
        if res[i] < res[i-1]:
            corrupted_idx = i
            break
            
    if corrupted_idx != -1:
        # Swap res[corrupted_idx] with something? 
        # Problem says "exactly one node contains an incorrect value".
        # Restore by sorting? No, structure must be preserved.
        # Just fix the value in the tree.
        # Find the node with value res[corrupted_idx] and change it to correct value?
        # Correct value should be such that sequence is sorted.
        # Simplest: Sort the values and re-assign? No, structure fixed.
        # If only one value is wrong, swapping it with its neighbor in sorted order might work?
        # Actually, if one value is wrong, the inorder traversal will have one or two inversions.
        # We can just sort the list of values and re-assign them to the nodes in inorder order.
        
        sorted_vals = sorted(res)
        
        # Re-assign
        def re_assign(node, it):
            if not node:
                return
            re_assign(node.left, it)
            node.val = next(it)
            re_assign(node.right, it)
            
        re_assign(root, iter(sorted_vals))
        
        # Print level order
        from collections import deque
        q = deque([root])
        out = []
        while q:
            node = q.popleft()
            out.append(str(node.val))
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        print(" ".join(out))
    else:
        print(" ".join(map(str, res)))

solve()

