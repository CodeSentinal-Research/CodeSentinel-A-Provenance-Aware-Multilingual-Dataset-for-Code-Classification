import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        x, y = abs(int(tokens[0])), abs(int(tokens[1]))
        q = deque([(0, 0, 0)])
        visited = {(0, 0)}
        dirs = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]
        while q:
            r, c, d = q.popleft()
            if r == x and c == y:
                print(d)
                return
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if -2 <= nr <= x + 2 and -2 <= nc <= y + 2 and (nr, nc) not in visited:
                    visited.add((nr, nc))
                    q.append((nr, nc, d + 1))
if __name__ == '__main__':
    main()