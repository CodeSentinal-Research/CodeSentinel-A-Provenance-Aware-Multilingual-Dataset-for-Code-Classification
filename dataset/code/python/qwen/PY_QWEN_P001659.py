import sys
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

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

def connect_next(root):
    if not root:
        return
    q = deque([root])
    while q:
        size = len(q)
        prev = None
        for _ in range(size):
            node = q.popleft()
            if prev:
                prev.next = node
            prev = node
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        prev.next = None

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
    connect_next(root)
    
    # Print next pointers level by level? "Print the value of the next pointer for every node in level order."
    # If next is None, print -1 or similar? Let's print value or -1.
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        if node.next:
            res.append(str(node.next.val))
        else:
            res.append("-1")
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    print(" ".join(res))

solve()

