import sys
def solve():
    s = int(sys.stdin.read().split()[0])
    count = 0
    for i in range(1, 7):
        for j in range(1, 7):
            if i + j == s:
                count += 1
    print(count / 36.0)
solve()
