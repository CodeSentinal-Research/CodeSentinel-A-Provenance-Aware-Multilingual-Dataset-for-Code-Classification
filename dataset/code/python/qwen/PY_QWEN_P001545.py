import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    min_diff = float('inf')
    
    for i in range(n - k + 1):
        window = nums[i:i+k]
        diff = max(window) - min(window)
        min_diff = min(min_diff, diff)
        
    print(min_diff)

solve()

