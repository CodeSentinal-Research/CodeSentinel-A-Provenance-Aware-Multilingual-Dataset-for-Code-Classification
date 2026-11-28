import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    target = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    total_sum = sum(nums)
    # Sum(P) - Sum(N) = Target
    # Sum(P) + Sum(N) = Total
    # 2*Sum(P) = Target + Total
    # Sum(P) = (Target + Total) / 2
    
    if (target + total_sum) % 2 != 0:
        print(0)
        return
        
    subset_sum = (target + total_sum) // 2
    if subset_sum < 0:
        print(0)
        return
        
    dp = [0] * (subset_sum + 1)
    dp[0] = 1
    
    for num in nums:
        for j in range(subset_sum, num - 1, -1):
            dp[j] += dp[j - num]
            
    print(dp[subset_sum])

if __name__ == "__main__":
    solve()

