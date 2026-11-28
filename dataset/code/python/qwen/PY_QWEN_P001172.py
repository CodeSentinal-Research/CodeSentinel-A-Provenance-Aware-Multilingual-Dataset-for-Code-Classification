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
        
    if grid[0][0] == 1 or grid[r-1][c-1] == 1:
        print(0)
        return
        
    dp = [[0]*c for _ in range(r)]
    dp[0][0] = 1
    
    for i in range(r):
        for j in range(c):
            if grid[i][j] == 1:
                dp[i][j] = 0
            else:
                if i > 0:
                    dp[i][j] += dp[i-1][j]
                if j > 0:
                    dp[i][j] += dp[i][j-1]
                    
    print(dp[r-1][c-1])

if __name__ == "__main__":
    solve()

