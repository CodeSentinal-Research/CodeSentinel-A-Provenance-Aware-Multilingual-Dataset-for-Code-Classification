import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    if n < 2: print("false")
    else:
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0: print("false"); return
        print("true")
solve()
