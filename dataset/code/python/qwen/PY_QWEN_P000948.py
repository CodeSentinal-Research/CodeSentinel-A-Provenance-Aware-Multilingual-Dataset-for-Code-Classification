import sys
def solve():
    d = sys.stdin.read().split()
    n, x, y = int(d[0]), int(d[1]), int(d[2])
    memo = {}
    def can_win(cx, cy):
        if (cx, cy) in memo: return memo[(cx, cy)]
        moves = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]
        for dx, dy in moves:
            nx, ny = cx + dx, cy + dy
            if 1 <= nx <= n and 1 <= ny <= n:
                if not can_win(nx, ny):
                    memo[(cx, cy)] = True
                    return True
        memo[(cx, cy)] = False
        return False
    print("First" if can_win(x, y) else "Second")
solve()
