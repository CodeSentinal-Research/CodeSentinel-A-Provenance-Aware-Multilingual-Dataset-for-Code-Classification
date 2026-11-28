import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    scores = list(map(int, input_data[idx:idx+n]))
    
    scores.sort()
    min_diff = float('inf')
    
    for i in range(n - k + 1):
        diff = scores[i + k - 1] - scores[i]
        min_diff = min(min_diff, diff)
        
    print(min_diff)

solve()

