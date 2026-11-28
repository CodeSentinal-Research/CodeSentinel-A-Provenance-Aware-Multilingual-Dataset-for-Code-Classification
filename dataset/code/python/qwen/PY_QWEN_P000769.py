import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    s1, s2 = d[0], d[1]
    memo = {}
    def rec(a, b):
        if a == b: return True
        if len(a) != len(b): return False
        if (a, b) in memo: return memo[(a, b)]
        if sorted(a) != sorted(b): return False
        for i in range(1, len(a)):
            if (rec(a[:i], b[:i]) and rec(a[i:], b[i:])) or (rec(a[:i], b[-i:]) and rec(a[i:], b[:-i])):
                memo[(a, b)] = True
                return True
        memo[(a, b)] = False
        return False
    print("true" if rec(s1, s2) else "false")
solve()
