import sys

class TreeNode:
    def __init__(self, val=0, priority=0, left=None, right=None):
        self.val = val
        self.priority = priority
        self.left = left
        self.right = right

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    keys = list(map(int, input_data[idx:idx+n])); idx += n
    priorities = list(map(int, input_data[idx:idx+n]))
    
    # Construct Cartesian Tree
    # Stack based approach
    stack = []
    root = None
    nodes = [TreeNode(k, p) for k, p in zip(keys, priorities)]
    
    for node in nodes:
        last = None
        while stack and stack[-1].priority > node.priority:
            last = stack.pop()
        node.left = last
        if stack:
            stack[-1].right = node
        stack.append(node)
        
    if stack:
        root = stack[0]
        
    # Print level order
    if not root:
        print("")
        return
    q = deque([root])
    res = []
    while q:
        node = q.popleft()
        res.append(str(node.val))
        if node.left: q.append(node.left)
        if node.right: q.append(node.right)
    print(" ".join(res))

solve()

