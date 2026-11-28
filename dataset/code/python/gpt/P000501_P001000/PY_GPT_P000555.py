# problem title : Minimum Reverse Operations
# Solve the stated task using standard input and standard output.
import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        p = int(tokens[1])
        b = int(tokens[2])
        banned = set(map(int, tokens[3:3+b]))
        k = int(tokens[3+b])
        res = [-1] * n
        res[p] = 0
        unvisited = [set(), set()]
        for i in range(n):
            if i != p and i not in banned:
                unvisited[i % 2].add(i)
        q = deque([p])
        while q:
            cur = q.popleft()
            min_idx = max(cur - k + 1, k - 1 - cur)
            max_idx = min(cur + k - 1, 2 * n - k - 1 - cur)
            parity = min_idx % 2
            to_remove = []
            for nxt in unvisited[parity]:
                if min_idx <= nxt <= max_idx:
                    res[nxt] = res[cur] + 1
                    q.append(nxt)
                    to_remove.append(nxt)
            for x in to_remove:
                unvisited[parity].remove(x)
        print(*res)
if __name__ == '__main__':
    main()
