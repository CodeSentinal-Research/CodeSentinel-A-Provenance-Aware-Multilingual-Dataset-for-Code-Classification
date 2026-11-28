import sys
def solve():
    d = sys.stdin.read().split()
    n = int(d[0])
    A = []
    idx = 1
    for i in range(n):
        A.append(list(map(int, d[idx:idx+n])))
        idx += n
    is_id = True
    for i in range(n):
        for j in range(n):
            if i == j and A[i][j] != 1: is_id = False
            if i != j and A[i][j] != 0: is_id = False
    print("true" if is_id else "false")
solve()
