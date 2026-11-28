import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    if n < 2:
        print("false")
        return
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            print("false")
            return
    print("true")
solve()
