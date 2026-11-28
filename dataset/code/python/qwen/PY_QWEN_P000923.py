import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    if n == 0:
        print(1)
        return
    res = 10
    for i in range(2, min(n + 1, 11)):
        res += 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 // (10 - i)
    print(res)
solve()
