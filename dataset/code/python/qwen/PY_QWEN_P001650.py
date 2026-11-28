import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree_in_post(ino, post):
    if not post:
        return None
    root_val = post[-1]
    root = TreeNode(root_val)
    idx = ino.index(root_val)
    root.left = build_tree_in_post(ino[:idx], post[:idx])
    root.right = build_tree_in_post(ino[idx+1:], post[idx:-1])
    return root

def level_order(root):
    if not root:
        return []
    from collections import deque
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    return " ".join(res)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    ino = list(map(int, input_data[idx:idx+n])); idx += n
    post = list(map(int, input_data[idx:idx+n]))
    
    root = build_tree_in_post(ino, post)
    print(level_order(root))

solve()

