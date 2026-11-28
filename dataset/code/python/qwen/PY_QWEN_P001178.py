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
    
    for j in range(c):
        dp[0][j] = grid[0][j]
        
    for j in range(1, c):
        for i in range(r):
            dp[i][j] = grid[i][j] + max(dp[i][j-1], dp[i-1][j-1] if i > 0 else 0, dp[i+1][j-1] if i < r - 1 else 0)
            
    print(max(dp[i][c-1] for i in range(r)))

if __name__ == "__main__":
    solve()

