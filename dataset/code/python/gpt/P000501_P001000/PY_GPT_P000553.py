# problem title : Snakes and Ladders
# Solve the stated task using standard input and standard output.
import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        idx = 1
        board = []
        for _ in range(n):
            board.append(list(map(int, tokens[idx:idx+n])))
            idx += n
        
        arr = [-1] * (n * n + 1)
        cur = 1
        for r in range(n - 1, -1, -1):
            row = board[r] if (n - 1 - r) % 2 == 0 else board[r][::-1]
            for val in row:
                arr[cur] = val
                cur += 1
        
        q = deque([(1, 0)])
        visited = {1}
        while q:
            pos, moves = q.popleft()
            if pos == n * n:
                print(moves)
                return
            for step in range(1, 7):
                nxt = pos + step
                if nxt <= n * n:
                    dest = arr[nxt] if arr[nxt] != -1 else nxt
                    if dest not in visited:
                        visited.add(dest)
                        q.append((dest, moves + 1))
        print(-1)
if __name__ == '__main__':
    main()
