import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    costs = []
    idx = 1
    for _ in range(n):
        costs.append(list(map(int, input_data[idx:idx+3])))
        idx += 3
        
    dp = [[0]*3 for _ in range(n)]
    dp[0] = costs[0]
    
    for i in range(1, n):
        dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2])
        dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2])
        dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1])
        
    print(min(dp[n-1]))

if __name__ == "__main__":
    solve()

