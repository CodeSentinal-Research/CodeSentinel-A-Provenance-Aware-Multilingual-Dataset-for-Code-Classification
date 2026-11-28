import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    diff = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    dp = {}
    max_len = 0
    
    for num in nums:
        prev_len = dp.get(num - diff, 0)
        dp[num] = prev_len + 1
        max_len = max(max_len, dp[num])
        
    print(max_len)

solve()

