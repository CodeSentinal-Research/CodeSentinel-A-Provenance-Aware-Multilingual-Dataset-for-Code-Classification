def min_visited_cell(m, n, grid):
    visited = [[0 for _ in range(n)] for _ in range(m)]
    queue = [(0, 0)]
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    
    while queue:
        x, y = queue.pop(0)
        if visited[x][y] == 1:
            continue
        visited[x][y] = 1
        if x == m - 1 and y == n - 1:
            return visited[x][y]
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < m and 0 <= ny < n and visited[nx][ny] == 0 and visited[x][y] + grid[nx][ny] < visited[x][y] + grid[x][y]:
                queue.append((nx, ny))
    return -1

def main():
    m, n = map(int, input().split())
    grid = []
    for _ in range(m):
        grid.append(list(map(int, input().split())))
    print(min_visited_cell(m, n, grid))

if __name__ == '__main__':
    main()