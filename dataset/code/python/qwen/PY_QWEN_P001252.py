import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    pairs = []
    for _ in range(n):
        a = int(input_data[idx]); idx += 1
        b = int(input_data[idx]); idx += 1
        pairs.append((a, b))
        
    pairs.sort(key=lambda x: x[1])
    
    count = 0
    last_end = -float('inf')
    
    for a, b in pairs:
        if a > last_end:
            count += 1
            last_end = b
            
    print(count)

if __name__ == "__main__":
    solve()

