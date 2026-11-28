import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    r = int(input_data[0])
    c = int(input_data[1])
    
    dp = [[1]*c for _ in range(r)]
    
    for i in range(1, r):
        for j in range(1, c):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
            
    print(dp[r-1][c-1])

if __name__ == "__main__":
    solve()

