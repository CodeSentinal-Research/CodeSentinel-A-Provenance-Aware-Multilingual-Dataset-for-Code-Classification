import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    target = int(d[2])
    matrix = [list(map(int, d[3+i*M:3+(i+1)*M])) for i in range(N)]
    l, r = 0, N * M - 1
    while l <= r:
        mid = (l + r) // 2
        val = matrix[mid // M][mid % M]
        if val == target:
            print("true")
            return
        elif val < target:
            l = mid + 1
        else:
            r = mid - 1
    print("false")
solve()
