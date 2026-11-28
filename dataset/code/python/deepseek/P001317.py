import sys
from queue import PriorityQueue

dx = [2, 2, -2, -2, 1, 1, -1, -1]
dy = [1, -1, 1, -1, 2, 2, 1, -1]

def is_valid(x, y, visited, n):
    if x >= 0 and x < n and y >= 0 and y < n and visited[x][y] == -1:
        return True
    return False

def find_tour(x, y, moves, n):
    if moves > n * n:
        return True
    for i in range(8):
        x1, y1 = x + dx[i], y + dy[i]
        if is_valid(x1, y1, moves, n):
            moves += 1
            visited[x1][y1] = moves
            if find_tour(x1, y1, moves, n):
                return True
            visited[x1][y1] = -1
    return False

def solve(n, start_x, start_y):
    moves = 1
    visited = [[-1] * n for _ in range(n)]
    visited[start_x][start_y] = 0
    if find_tour(start_x, start_y, moves, n):
        return visited
    print("IMPOSSIBLE")
    sys.exit(0)

def main():
    n = int(input().strip())
    start_x, start_y = map(int, input().strip().split())
    start_x -= 1
    start_y -= 1
    visited = solve(n, start_x, start_y)
    if visited:
        for i in range(n):
            for j in range(n):
                print(visited[i][j], end=' ')
            print()
    else:
        print("IMPOSSIBLE")

if __name__ == "__main__":
    main()