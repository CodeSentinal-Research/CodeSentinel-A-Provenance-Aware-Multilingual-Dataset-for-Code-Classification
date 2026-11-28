import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    r = int(input_data[0])
    
    edge_counts = defaultdict(int)
    total_width = 0
    
    for i in range(r):
        parts = list(map(int, input_data[i+1].split()))
        num_bricks = parts[0]
        widths = parts[1:]
        total_width = sum(widths)
        
        current_pos = 0
        for w in widths[:-1]: # Last brick doesn't create an internal edge
            current_pos += w
            edge_counts[current_pos] += 1
            
    if not edge_counts:
        print(r)
        return
        
    max_crossings = max(edge_counts.values())
    print(r - max_crossings)

solve()

