import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    target = int(d[2])
    matrix = [list(map(int, d[3+i*M:3+(i+1)*M])) for i in range(N)]
    r, c = 0, M - 1
    while r < N and c >= 0:
        if matrix[r][c] == target:
            print("true")
            return
        elif matrix[r][c] > target:
            c -= 1
        else:
            r += 1
    print("false")
solve()
