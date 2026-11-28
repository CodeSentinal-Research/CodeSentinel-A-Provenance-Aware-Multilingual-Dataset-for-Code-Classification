import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    r = int(input_data[idx]); idx += 1
    c = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    sr = int(input_data[idx]); idx += 1
    sc = int(input_data[idx]); idx += 1
    
    MOD = 10**9 + 7
    dp = [[[0] * c for _ in range(r)] for _ in range(k + 1)]
    dp[0][sr][sc] = 1
    
    moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    paths = 0
    
    for step in range(1, k + 1):
        for i in range(r):
            for j in range(c):
                for dr, dc in moves:
                    ni, nj = i + dr, j + dc
                    if 0 <= ni < r and 0 <= nj < c:
                        dp[step][i][j] = (dp[step][i][j] + dp[step-1][ni][nj]) % MOD
                    else:
                        if step == k: # This logic is slightly off for "at most K"
                             pass 

    # Correct approach: Sum paths that go out of bounds at any step <= K
    # Or simpler: Total paths - Paths staying inside.
    # Let's use direct counting of exiting paths.
    
    total_exits = 0
    # Re-initialize for exit counting
    dp_in = [[[0] * c for _ in range(r)] for _ in range(k + 1)]
    dp_in[0][sr][sc] = 1
    
    for step in range(1, k + 1):
        for i in range(r):
            for j in range(c):
                for dr, dc in moves:
                    ni, nj = i + dr, j + dc
                    if 0 <= ni < r and 0 <= nj < c:
                        dp_in[step][i][j] = (dp_in[step][i][j] + dp_in[step-1][ni][nj]) % MOD
                    else:
                        total_exits = (total_exits + dp_in[step-1][i][j]) % MOD
                        
    print(total_exits)

if __name__ == "__main__":
    solve()

