import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def insert_bst(root, val):
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_bst(root.left, val)
    else:
        root.right = insert_bst(root.right, val)
    return root

def is_identical(t1, t2):
    if not t1 and not t2:
        return True
    if not t1 or not t2:
        return False
    return t1.val == t2.val and is_identical(t1.left, t2.left) and is_identical(t1.right, t2.right)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    seq1 = list(map(int, input_data[idx:idx+n])); idx += n
    seq2 = list(map(int, input_data[idx:idx+n]))
    
    t1 = None
    for v in seq1:
        t1 = insert_bst(t1, v)
        
    t2 = None
    for v in seq2:
        t2 = insert_bst(t2, v)
        
    print("YES" if is_identical(t1, t2) else "NO")

solve()

