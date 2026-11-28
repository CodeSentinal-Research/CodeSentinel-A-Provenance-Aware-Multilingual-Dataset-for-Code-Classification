from typing import List

def paths_with_sum_grid(grid: List[List[int]], target: int) -> int:
    m, n = len(grid), len(grid[0])
    memo = {}

    def dfs(r, c, cur_sum):
        if r >= m or c >= n:
            return 0
        cur_sum += grid[r][c]
        if r == m - 1 and c == n - 1:
            return 1 if cur_sum == target else 0
        state = (r, c, cur_sum)
        if state in memo:
            return memo[state]
        ans = dfs(r + 1, c, cur_sum) + dfs(r, c + 1, cur_sum)
        memo[state] = ans
        return ans

    return dfs(0, 0, 0)

if __name__ == '__main__':
    m, n, target = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(m)]
    print(paths_with_sum_grid(grid, target))