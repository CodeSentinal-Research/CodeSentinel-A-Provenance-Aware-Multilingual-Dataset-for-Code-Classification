import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    s, K = d[0], int(d[1])
    def rec(i, size):
        if i == len(s): return 0
        if s[i].isalpha():
            if size == K: return s[i]
            return rec(i + 1, size + 1)
        else:
            num = int(s[i])
            if size % num == 0: return rec(i + 1, size // num)
            return rec(i + 1, size)
    print(rec(0, 1))
solve()
