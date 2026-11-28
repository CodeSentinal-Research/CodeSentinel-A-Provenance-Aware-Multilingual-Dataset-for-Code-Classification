import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    def rec(l, r):
        if l >= r: return 0
        m = (l + r) // 2
        inv = rec(l, m) + rec(m + 1, r)
        temp = []
        i, j = l, m + 1
        while i <= m and j <= r:
            if arr[i] <= arr[j]:
                temp.append(arr[i]); i += 1
            else:
                temp.append(arr[j]); inv += (m - i + 1); j += 1
        while i <= m: temp.append(arr[i]); i += 1
        while j <= r: temp.append(arr[j]); j += 1
        for k in range(len(temp)): arr[l+k] = temp[k]
        return inv
    print(rec(0, n - 1))
solve()
