import sys
def solve():
    s = sys.stdin.read().split()[0]
    def rec(idx, prev):
        if idx == len(s): return True
        for i in range(idx + 1, len(s) + 1):
            val = int(s[idx:i])
            if prev != -1 and val >= prev: return False
            if prev == -1 or val == prev - 1:
                if rec(i, val): return True
            if prev != -1: break
        return False
    print("true" if rec(0, -1) else "false")
solve()
