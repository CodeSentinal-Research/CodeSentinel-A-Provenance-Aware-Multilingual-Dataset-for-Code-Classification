# problem title : Binary Tree Vertical Order Traversal
# Solve the stated task using standard input and standard output.
import sys
from collections import defaultdict, deque
def main():
    tokens = sys.stdin.read().split()
    if not tokens or tokens[0] in ("null", "#", "N"): return
    tree = [None if t in ("null", "#", "N") else int(t) for t in tokens]
    cols = defaultdict(list)
    q = deque([(0, 0)]) # (idx, col)
    while q:
        idx, col = q.popleft()
        if idx >= len(tree) or tree[idx] is None: continue
        cols[col].append(tree[idx])
        l, r = 2 * idx + 1, 2 * idx + 2
        if l < len(tree): q.append((l, col - 1))
        if r < len(tree): q.append((r, col + 1))
    for c in sorted(cols):
        print(*cols[c])
if __name__ == '__main__':
    main()
