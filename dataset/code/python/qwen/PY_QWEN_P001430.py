import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    a = list(map(int, input_data[idx:idx+n])); idx += n
    b = list(map(int, input_data[idx:idx+n]))
    
    seen_a = set()
    seen_b = set()
    common = 0
    result = []
    
    for i in range(n):
        seen_a.add(a[i])
        seen_b.add(b[i])
        common = len(seen_a & seen_b)
        result.append(common)
        
    print(*result)

solve()

