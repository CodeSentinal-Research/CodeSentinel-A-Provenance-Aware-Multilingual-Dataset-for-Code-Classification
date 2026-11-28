import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    insertion_seq = list(map(int, input_data[idx:idx+n]))
    
    if not insertion_seq:
        print(0)
        return
        
    # Simulate insertion to find height
    class Node:
        def __init__(self, val):
            self.val = val
            self.left = None
            self.right = None
            
    root = Node(insertion_seq[0])
    max_depth = 0
    
    for v in insertion_seq[1:]:
        curr = root
        depth = 0
        while True:
            depth += 1
            if v < curr.val:
                if not curr.left:
                    curr.left = Node(v)
                    break
                curr = curr.left
            else:
                if not curr.right:
                    curr.right = Node(v)
                    break
                curr = curr.right
        max_depth = max(max_depth, depth)
        
    print(max_depth)

solve()

