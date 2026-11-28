Here is the Python code:

def minCost(R, C, grid):
    dp = [[0]*C for _ in range(R)]
    
    for i in range(1, R):
        dp[i][0] = dp[i-1][0] + grid[i][0]
    for j in range(1, C):
        dp[0][j] = dp[0][j-1] + grid[0][j]
        
    for i in range(1, R):
        for j in range(1, C):
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
            
    return dp[R-1][C-1]

def main():
    R = int(input().strip())
    C = int(input().strip())
    
    grid = []
    for i in range(R):
        row = [int(x) for x in input().strip().split()]
        grid.append(row)
        
    print(minCost(R, C, grid))

if __name__ == "__main__":
    main()

This code first reads the number of rows R and columns C, then it reads the grid. It then calls the `minCost` function, which calculates and returns the minimum cost to reach the bottom-right corner from the top-left corner by moving only right or down. Finally, it prints the result.

The `minCost` function uses a dynamic programming approach to solve the problem. It first creates a 2D array `dp` to hold the minimum cost. Then it fills up the `dp` array in a bottom-up manner. The cost of reaching the bottom-right corner from any cell (i, j) is the minimum cost of reaching from its top-left neighbor (i-1, j) and from its top neighbor (i, j-1) plus the cost of moving from the top-left corner to the current cell.

The `main` function first reads the number of rows R and columns C, then it reads the grid. It then calls the `minCost` function with the grid and the values of R and C, and prints the result.