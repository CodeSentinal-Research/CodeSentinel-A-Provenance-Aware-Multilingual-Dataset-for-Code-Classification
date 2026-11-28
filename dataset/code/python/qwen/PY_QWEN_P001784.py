import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree_level_inorder(level_order, inorder):
    if not level_order or not inorder:
        return None
    root_val = level_order[0]
    root = TreeNode(root_val)
    
    idx = inorder.index(root_val)
    left_in = inorder[:idx]
    right_in = inorder[idx+1:]
    
    left_level = [x for x in level_order if x in left_in]
    right_level = [x for x in level_order if x in right_in]
    
    root.left = build_tree_level_inorder(left_level, left_in)
    root.right = build_tree_level_inorder(right_level, right_in)
    
    return root

def level_order_print(root):
    if not root:
        return []
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
    level_order = list(map(int, input_data[idx:idx+n])); idx += n
    inorder = list(map(int, input_data[idx:idx+n]))
    
    root = build_tree_level_inorder(level_order, inorder)
    print(level_order_print(root))

solve()

