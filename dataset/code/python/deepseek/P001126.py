from heapq import heappop, heappush

def solve(R, C, heights):
    efforts = [[float('inf')] * C for _ in range(R)]
    efforts[0][0] = 0
    heap = [(0, (0, 0))]
    while heap:
        curr_effort, (x, y) = heappop(heap)
        if (x, y) == (R - 1, C - 1):
            return curr_effort
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < R and 0 <= ny < C:
                new_effort = max(curr_effort, abs(heights[x][y] - heights[nx][ny]))
                if new_effort < efforts[nx][ny]:
                    efforts[nx][ny] = new

R, C = map(int, input().split())
heights = [list(map(int, input().split())) for _ in range(R)]
print(solve(R, C, heights))