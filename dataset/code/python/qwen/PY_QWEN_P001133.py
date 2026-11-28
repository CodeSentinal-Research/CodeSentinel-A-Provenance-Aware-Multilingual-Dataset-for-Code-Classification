import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    cost = list(map(int, input_data[1:1+n]))
    
    if n == 2:
        print(min(cost[0], cost[1]))
        return
        
    dp = [0] * n
    dp[0] = cost[0]
    dp[1] = cost[1]
    
    for i in range(2, n):
        dp[i] = cost[i] + min(dp[i-1], dp[i-2])
        
    print(min(dp[n-1], dp[n-2]))

if __name__ == "__main__":
    solve()

