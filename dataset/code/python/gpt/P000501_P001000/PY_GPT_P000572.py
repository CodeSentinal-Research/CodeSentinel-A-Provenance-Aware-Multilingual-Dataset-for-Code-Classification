# problem title : Binary Tree Level Order Traversal
# Solve the stated task using standard input and standard output.
import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if not tokens or tokens[0] in ("null", "#", "N"):
        return
    # Build tree from level order
    tree = []
    for t in tokens:
        if t in ("null", "#", "N"): tree.append(None)
        else: tree.append(int(t))
    levels = []
    q = deque([(0, 0)]) # (index in tree array, level)
    cur_lvl = -1
    while q:
        idx, lvl = q.popleft()
        if idx >= len(tree) or tree[idx] is None: continue
        if lvl >= len(levels): levels.append([])
        levels[lvl].append(tree[idx])
        left_idx = 2 * idx + 1
        right_idx = 2 * idx + 2
        if left_idx < len(tree): q.append((left_idx, lvl + 1))
        if right_idx < len(tree): q.append((right_idx, lvl + 1))
    for lvl in levels:
        print(*lvl)
if __name__ == '__main__':
    main()
