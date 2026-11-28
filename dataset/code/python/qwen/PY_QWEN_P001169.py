import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    r = int(input_data[idx]); idx += 1
    c = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(r):
        grid.append(list(map(int, input_data[idx:idx+c])))
        idx += c
        
    dp = [[0]*c for _ in range(r)]
    
    for i in range(r - 1, -1, -1):
        for j in range(c - 1, -1, -1):
            if i == r - 1 and j == c - 1:
                dp[i][j] = max(1, 1 - grid[i][j])
            elif i == r - 1:
                dp[i][j] = max(1, dp[i][j+1] - grid[i][j])
            elif j == c - 1:
                dp[i][j] = max(1, dp[i+1][j] - grid[i][j])
            else:
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - grid[i][j])
                
    print(dp[0][0])

if __name__ == "__main__":
    solve()

