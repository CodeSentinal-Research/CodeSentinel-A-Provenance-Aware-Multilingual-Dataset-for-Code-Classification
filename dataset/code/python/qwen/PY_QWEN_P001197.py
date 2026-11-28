import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    dp = [defaultdict(int) for _ in range(n)]
    count = 0
    
    for i in range(n):
        for j in range(i):
            diff = nums[i] - nums[j]
            dp[i][diff] += dp[j][diff] + 1
            count += dp[j][diff]
            
    print(count)

if __name__ == "__main__":
    solve()

