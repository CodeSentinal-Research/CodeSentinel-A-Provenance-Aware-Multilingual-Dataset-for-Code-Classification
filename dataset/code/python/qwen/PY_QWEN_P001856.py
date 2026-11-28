import sys

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

def bst_to_dll(root):
    if not root:
        return None
    head = tail = None
    
    def inorder(node):
        nonlocal head, tail
        if not node:
            return
        inorder(node.left)
        if not tail:
            head = node
        else:
            tail.right = node
            node.left = tail
        tail = node
        inorder(node.right)
        
    inorder(root)
    # Make circular
    if head and tail:
        head.left = tail
        tail.right = head
    return head

def print_dll(head):
    if not head:
        return
    res = []
    curr = head
    while True:
        res.append(str(curr.val))
        curr = curr.right
        if curr == head:
            break
    print(" ".join(res))

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    vals = []
    for _ in range(n):
        v = int(input_data[idx]); idx += 1
        vals.append(v if v != -1 else None)
        
    root = build_tree(vals)
    head = bst_to_dll(root)
    print_dll(head)

solve()

