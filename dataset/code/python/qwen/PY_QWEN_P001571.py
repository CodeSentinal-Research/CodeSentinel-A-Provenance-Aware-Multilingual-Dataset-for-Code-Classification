import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    results = []
    for i in range(n - k + 1):
        results.append(nums[i+k-1] - nums[i])
        
    print(*results)

solve()

