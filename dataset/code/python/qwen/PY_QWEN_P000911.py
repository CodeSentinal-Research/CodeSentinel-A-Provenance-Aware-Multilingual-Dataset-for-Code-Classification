import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    res = []
    for i in range(n):
        row = [1]
        for j in range(1, i):
            row.append(res[i-1][j-1] + res[i-1][j])
        if i > 0:
            row.append(1)
        res.append(row)
    for row in res:
        print(" ".join(map(str, row)))
solve()
