import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, arr = int(d[0]), list(map(int, d[1:]))
    tot = sum(arr)
    res = [float('inf'), []]
    def rec(idx, s1, s2, c1, c2, p1, p2):
        if idx == N:
            if abs(s1 - s2) < res[0]:
                res[0] = abs(s1 - s2)
                res[1] = p1[:]
            return
        if c1 < (N + 1) // 2:
            p1.append(arr[idx])
            rec(idx + 1, s1 + arr[idx], s2, c1 + 1, c2, p1, p2)
            p1.pop()
        if c2 < (N + 1) // 2:
            p2.append(arr[idx])
            rec(idx + 1, s1, s2 + arr[idx], c1, c2 + 1, p1, p2)
            p2.pop()
    rec(0, 0, 0, 0, 0, [], [])
    print(res[0])
    print(" ".join(map(str, res[1])))
solve()
