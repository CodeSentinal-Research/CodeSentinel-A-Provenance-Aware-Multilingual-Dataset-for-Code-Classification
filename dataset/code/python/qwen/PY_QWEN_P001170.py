import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input_data[idx:idx+n])))
        idx += n
        
    # 3D DP: dp[r1][c1][r2] -> c2 = r1+c1-r2
    dp = [[[-1]*(n) for _ in range(n)] for _ in range(n)]
    
    def helper(r1, c1, r2):
        c2 = r1 + c1 - r2
        if r1 == n or c1 == n or r2 == n or c2 == n:
            return -1
        if grid[r1][c1] == -1 or grid[r2][c2] == -1:
            return -1
        if dp[r1][c1][r2] != -1:
            return dp[r1][c1][r2]
            
        if r1 == n - 1 and c1 == n - 1:
            return grid[r1][c1]
            
        cherries = grid[r1][c1]
        if r1 != r2:
            cherries += grid[r2][c2]
            
        best = -1
        for dr1, dc1 in [(1,0), (0,1)]:
            for dr2, dc2 in [(1,0), (0,1)]:
                val = helper(r1+dr1, c1+dc1, r2+dr2)
                if val != -1:
                    best = max(best, val)
                    
        dp[r1][c1][r2] = best + cherries if best != -1 else -1
        return dp[r1][c1][r2]
        
    print(max(0, helper(0, 0, 0)))

if __name__ == "__main__":
    solve()

