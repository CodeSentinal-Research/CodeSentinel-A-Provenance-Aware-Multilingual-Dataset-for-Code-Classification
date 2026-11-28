import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def postorder_to_bst(postorder):
    if not postorder:
        return None
    root = TreeNode(postorder[-1])
    stack = [root]
    for val in reversed(postorder[:-1]):
        node = TreeNode(val)
        if val > stack[-1].val:
            stack[-1].right = node
        else:
            parent = None
            while stack and val < stack[-1].val:
                parent = stack.pop()
            if parent:
                parent.left = node
            else:
                stack[-1].left = node
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
    postorder = list(map(int, input_data[idx:idx+n]))
    
    root = postorder_to_bst(postorder)
    print(level_order(root))

solve()

