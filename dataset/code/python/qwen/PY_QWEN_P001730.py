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

def tree_to_dll(node):
    if not node:
        return None, None
    if not node.left and not node.right:
        return node, node
        
    left_head, left_tail = tree_to_dll(node.left)
    right_head, right_tail = tree_to_dll(node.right)
    
    if left_tail:
        left_tail.right = node
        node.left = left_tail
    if right_head:
        node.right = right_head
        right_head.left = node
        
    head = left_head if left_head else node
    tail = right_tail if right_tail else node
    
    # Make circular
    head.left = tail
    tail.right = head
    
    return head, tail

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
    head, _ = tree_to_dll(root)
    print_dll(head)

solve()

