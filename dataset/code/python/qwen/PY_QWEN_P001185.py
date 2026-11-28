import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    counter = Counter(nums)
    max_val = max(nums)
    
    dp = [0] * (max_val + 1)
    dp[1] = counter[1]
    
    for i in range(2, max_val + 1):
        dp[i] = max(dp[i-1], dp[i-2] + i * counter[i])
        
    print(dp[max_val])

if __name__ == "__main__":
    solve()

