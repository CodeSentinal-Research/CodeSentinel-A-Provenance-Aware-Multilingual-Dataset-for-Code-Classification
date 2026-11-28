import sys
def solve():
    d = sys.stdin.read().split()
    n = int(d[0])
    A = []
    idx = 1
    for i in range(n):
        A.append(list(map(int, d[idx:idx+n])))
        idx += n
    is_sym = True
    for i in range(n):
        for j in range(n):
            if A[i][j] != A[j][i]:
                is_sym = False
                break
    print("true" if is_sym else "false")
solve()
