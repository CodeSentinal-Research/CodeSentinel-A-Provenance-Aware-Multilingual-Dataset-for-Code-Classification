import sys

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    first_line = input_data[0].split()
    n = int(first_line[0])
    m = int(first_line[1])
    target = int(first_line[2])
    
    grid = []
    for i in range(1, n + 1):
        grid.append(list(map(int, input_data[i].split())))
        
    # DP with memoization
    from functools import lru_cache
    
    @lru_cache(None)
    def dp(r, c, curr_sum):
        if r == n - 1 and c == m - 1:
            return 1 if curr_sum + grid[r][c] == target else 0
        
        count = 0
        if r + 1 < n:
            count += dp(r + 1, c, curr_sum + grid[r][c])
        if c + 1 < m:
            count += dp(r, c + 1, curr_sum + grid[r][c])
        return count
        
    print(dp(0, 0, 0))

solve()

