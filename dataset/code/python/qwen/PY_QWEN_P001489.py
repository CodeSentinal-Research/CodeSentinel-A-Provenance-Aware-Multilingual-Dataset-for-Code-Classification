import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    target = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    nums.sort()
    MOD = 10**9 + 7
    count = 0
    
    for left in range(n):
        right = n - 1
        while left < right and nums[left] + nums[right] > target:
            right -= 1
        if left < right:
            count += pow(2, right - left, MOD)
            
    print(count % MOD)

solve()

