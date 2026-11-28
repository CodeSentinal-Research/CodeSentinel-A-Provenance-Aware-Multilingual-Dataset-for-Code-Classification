import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    r = int(input_data[2]) - 1
    c = int(input_data[3]) - 1
    
    dp = [[[0.0] * n for _ in range(n)] for _ in range(k + 1)]
    dp[0][r][c] = 1.0
    
    moves = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
    
    for step in range(1, k + 1):
        for i in range(n):
            for j in range(n):
                for dr, dc in moves:
                    ni, nj = i + dr, j + dc
                    if 0 <= ni < n and 0 <= nj < n:
                        dp[step][ni][nj] += dp[step-1][i][j] / 8.0
                        
    prob = 0.0
    for i in range(n):
        for j in range(n):
            prob += dp[k][i][j]
            
    print("{:.6f}".format(prob))

if __name__ == "__main__":
    solve()

