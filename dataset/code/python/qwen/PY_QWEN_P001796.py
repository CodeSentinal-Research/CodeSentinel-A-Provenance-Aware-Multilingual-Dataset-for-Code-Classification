import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def preorder_to_bst(preorder):
    if not preorder:
        return None
    root = TreeNode(preorder[0])
    stack = [root]
    for val in preorder[1:]:
        node = TreeNode(val)
        if val < stack[-1].val:
            stack[-1].left = node
        else:
            parent = None
            while stack and val > stack[-1].val:
                parent = stack.pop()
            parent.right = node
        stack.append(node)
    return root

def level_order(root):
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
    preorder = list(map(int, input_data[idx:idx+n]))
    
    root = preorder_to_bst(preorder)
    print(level_order(root))

solve()

