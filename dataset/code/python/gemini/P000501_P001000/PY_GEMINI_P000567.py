import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        m = int(tokens[0])
        n = int(tokens[1])
        idx = 2
        forest = []
        trees = []
        for r in range(m):
            row = []
            for c in range(n):
                val = int(tokens[idx])
                row.append(val)
                if val > 1: trees.append((val, r, c))
                idx += 1
            forest.append(row)
        trees.sort()
        
        def bfs(sr, sc, tr, tc):
            if sr == tr and sc == tc: return 0
            q = deque([(sr, sc, 0)])
            vis = {(sr, sc)}
            while q:
                r, c, d = q.popleft()
                for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and forest[nr][nc] != 0 and (nr, nc) not in vis:
                        if nr == tr and nc == tc: return d + 1
                        vis.add((nr, nc))
                        q.append((nr, nc, d + 1))
            return -1

        total_steps = 0
        cur_r, cur_c = 0, 0
        for val, tr, tc in trees:
            steps = bfs(cur_r, cur_c, tr, tc)
            if steps == -1:
                print(-1)
                return
            total_steps += steps
            cur_r, cur_c = tr, tc
        print(total_steps)
if __name__ == '__main__':
    main()