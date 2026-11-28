import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    phi = list(range(n + 1))
    for i in range(2, n + 1):
        if phi[i] == i:
            for j in range(i, n + 1, i):
                phi[j] -= phi[j] // i
    print(" ".join(map(str, phi[1:])))
solve()
