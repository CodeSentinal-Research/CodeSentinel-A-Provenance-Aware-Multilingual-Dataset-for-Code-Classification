# problem title : Nearest Exit from Maze
# Solve the stated task using standard input and standard output.
import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        m = int(tokens[0])
        n = int(tokens[1])
        maze = tokens[2:2+m]
        er = int(tokens[2+m])
        ec = int(tokens[3+m])
        q = deque([(er, ec, 0)])
        visited = {(er, ec)}
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while q:
            r, c, d = q.popleft()
            if (r != er or c != ec) and (r == 0 or r == m - 1 or c == 0 or c == n - 1):
                print(d)
                return
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and maze[nr][nc] == '.' and (nr, nc) not in visited:
                    visited.add((nr, nc))
                    q.append((nr, nc, d + 1))
        print(-1)
if __name__ == '__main__':
    main()
