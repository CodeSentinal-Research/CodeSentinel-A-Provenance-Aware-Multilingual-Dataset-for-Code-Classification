import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree_pre_post(pre, post):
    if not pre:
        return None
    root = TreeNode(pre[0])
    if len(pre) == 1:
        return root
    # Left child is pre[1]
    # Find pre[1] in post to determine left subtree size
    left_root_val = pre[1]
    idx = post.index(left_root_val)
    left_size = idx + 1
    
    root.left = build_tree_pre_post(pre[1:1+left_size], post[:left_size])
    root.right = build_tree_pre_post(pre[1+left_size:], post[left_size:-1])
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
    pre = list(map(int, input_data[idx:idx+n])); idx += n
    post = list(map(int, input_data[idx:idx+n]))
    
    root = build_tree_pre_post(pre, post)
    print(level_order(root))

solve()

