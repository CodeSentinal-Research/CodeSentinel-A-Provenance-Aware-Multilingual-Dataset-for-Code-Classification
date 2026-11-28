import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if not tokens or tokens[0] in ("null", "#", "N"):
        print(0)
        return
    tree = [None if t in ("null", "#", "N") else int(t) for t in tokens]
    max_w = 0
    q = deque([(0, 1)]) # (tree_array_index, pos_id)
    while q:
        sz = len(q)
        first_pos, last_pos = q[0][1], q[-1][1]
        max_w = max(max_w, last_pos - first_pos + 1)
        for _ in range(sz):
            idx, pos = q.popleft()
            l, r = 2 * idx + 1, 2 * idx + 2
            if l < len(tree) and tree[l] is not None:
                q.append((l, 2 * pos))
            if r < len(tree) and tree[r] is not None:
                q.append((r, 2 * pos + 1))
    print(max_w)
if __name__ == '__main__':
    main()