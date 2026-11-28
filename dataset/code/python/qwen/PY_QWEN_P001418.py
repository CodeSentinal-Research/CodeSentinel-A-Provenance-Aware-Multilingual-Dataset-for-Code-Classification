import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    allowed = set(input_data[idx]); idx += 1
    n = int(input_data[idx]); idx += 1
    
    count = 0
    for _ in range(n):
        word = input_data[idx]; idx += 1
        if all(c in allowed for c in word):
            count += 1
            
    print(count)

solve()

