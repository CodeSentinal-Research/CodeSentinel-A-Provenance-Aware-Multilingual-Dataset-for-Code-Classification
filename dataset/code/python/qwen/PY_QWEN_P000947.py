import sys
def solve():
    d = sys.stdin.read().split()
    max_c, target = int(d[0]), int(d[1])
    memo = {}
    def can_win(used_mask, curr_sum):
        if curr_sum >= target: return False
        if used_mask in memo: return memo[used_mask]
        for i in range(1, max_c + 1):
            if not (used_mask & (1 << i)):
                if not can_win(used_mask | (1 << i), curr_sum + i):
                    memo[used_mask] = True
                    return True
        memo[used_mask] = False
        return False
    print("true" if can_win(0, 0) else "false")
solve()
