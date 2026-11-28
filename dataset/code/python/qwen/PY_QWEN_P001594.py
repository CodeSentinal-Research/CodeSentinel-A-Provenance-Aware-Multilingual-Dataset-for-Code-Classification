import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    prefix = [0] * n
    prefix[0] = nums[0]
    for i in range(1, n):
        prefix[i] = prefix[i-1] + nums[i]
        
    print(*prefix)

solve()

