import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    destinations = set()
    sources = set()
    
    for _ in range(n):
        src = input_data[idx]; idx += 1
        dst = input_data[idx]; idx += 1
        sources.add(src)
        destinations.add(dst)
        
    for dst in destinations:
        if dst not in sources:
            print(dst)
            return

solve()

