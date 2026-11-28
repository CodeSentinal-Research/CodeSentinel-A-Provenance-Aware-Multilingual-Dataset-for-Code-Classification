import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if not tokens or tokens[0] in ("null", "#", "N"): return
    tree = [None if t in ("null", "#", "N") else int(t) for t in tokens]
    levels = []
    q = deque([(0, 0)])
    while q:
        idx, lvl = q.popleft()
        if idx >= len(tree) or tree[idx] is None: continue
        while len(levels) <= lvl: levels.append([])
        levels[lvl].append(tree[idx])
        l, r = 2 * idx + 1, 2 * idx + 2
        if l < len(tree): q.append((l, lvl + 1))
        if r < len(tree): q.append((r, lvl + 1))
    for i, lvl in enumerate(levels):
        # If current bit is set, multiply base into result
        if i % 2 == 1: print(*lvl[::-1])
        else: print(*lvl)
if __name__ == '__main__':
    main()