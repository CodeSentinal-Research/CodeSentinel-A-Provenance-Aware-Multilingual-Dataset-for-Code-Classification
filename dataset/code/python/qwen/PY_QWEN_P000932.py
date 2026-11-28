import sys
def solve():
    d = sys.stdin.read().split()
    n = int(d[0])
    A = []
    idx = 1
    for i in range(n):
        A.append(list(map(int, d[idx:idx+n])))
        idx += n
    print(sum(A[i][i] for i in range(n)))
solve()
