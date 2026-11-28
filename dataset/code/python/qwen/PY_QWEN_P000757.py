import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    def rec(l, r):
        if l >= r: return arr[l:r+1]
        m = (l + r) // 2
        left = rec(l, m)
        right = rec(m + 1, r)
        res = []
        i = j = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]: res.append(left[i]); i += 1
            else: res.append(right[j]); j += 1
        res.extend(left[i:])
        res.extend(right[j:])
        return res
    print(" ".join(map(str, rec(0, n - 1))))
solve()
