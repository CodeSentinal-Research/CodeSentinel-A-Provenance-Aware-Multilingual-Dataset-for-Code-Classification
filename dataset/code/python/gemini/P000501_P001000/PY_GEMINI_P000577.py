import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if not tokens or tokens[0] in ("null", "#", "N"): return
    tree = [None if t in ("null", "#", "N") else int(t) for t in tokens]
    bottom = {}
    q = deque([(0, 0)])
    while q:
        idx, col = q.popleft()
        if idx >= len(tree) or tree[idx] is None: continue
        bottom[col] = tree[idx]
        l, r = 2 * idx + 1, 2 * idx + 2
        if l < len(tree): q.append((l, col - 1))
        if r < len(tree): q.append((r, col + 1))
    res = [bottom[c] for c in sorted(bottom)]
    print(*res)
if __name__ == '__main__':
    main()