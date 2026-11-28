import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        m = int(tokens[0])
        n = int(tokens[1])
        idx = 2
        grid = []
        fire_q = deque()
        fire_time = [[float('inf')] * n for _ in range(m)]
        for r in range(m):
            row = []
            for c in range(n):
                val = int(tokens[idx])
                row.append(val)
                if val == 1:
                    fire_q.append((r, c, 0))
                    fire_time[r][c] = 0
                idx += 1
            grid.append(row)
        
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while fire_q:
            r, c, t = fire_q.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 0 and fire_time[nr][nc] == float('inf'):
                    fire_time[nr][nc] = t + 1
                    fire_q.append((nr, nc, t + 1))
        
        def can_escape(wait_time):
            if fire_time[0][0] <= wait_time: return False
            q = deque([(0, 0, wait_time)])
            visited = [[False] * n for _ in range(m)]
            visited[0][0] = True
            while q:
                r, c, t = q.popleft()
                if r == m - 1 and c == n - 1: return True
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 0 and not visited[nr][nc]:
                        if nr == m - 1 and nc == n - 1:
                            if t + 1 <= fire_time[nr][nc]: return True
                        elif t + 1 < fire_time[nr][nc]:
                            visited[nr][nc] = True
                            q.append((nr, nc, t + 1))
            return False

        low, high = 0, 10**9
        ans = -1
        # Binary search: narrow range until pointers cross
        while low <= high:
            # Calculate midpoint to prevent potential overflow
            mid = (low + high) // 2
            if can_escape(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        print(ans)
if __name__ == '__main__':
    main()