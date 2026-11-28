import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    points = []
    for _ in range(n):
        points.append(list(map(int, input_data[idx:idx+3])))
        idx += 3
        
    dp = [[0]*3 for _ in range(n)]
    dp[0] = points[0]
    
    for i in range(1, n):
        dp[i][0] = points[i][0] + max(dp[i-1][1], dp[i-1][2])
        dp[i][1] = points[i][1] + max(dp[i-1][0], dp[i-1][2])
        dp[i][2] = points[i][2] + max(dp[i-1][0], dp[i-1][1])
        
    print(max(dp[n-1]))

if __name__ == "__main__":
    solve()

