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
    max_side = 0
    
    for i in range(r):
        for j in range(c):
            if grid[i][j] == 1:
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                max_side = max(max_side, dp[i][j])
                
    print(max_side * max_side)

if __name__ == "__main__":
    solve()

