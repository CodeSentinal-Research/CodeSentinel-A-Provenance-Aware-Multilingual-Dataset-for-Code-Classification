import sys
def solve():
    x = int(sys.stdin.read().split()[0])
    sign = -1 if x < 0 else 1
    res = int(str(abs(x))[::-1]) * sign
    if res < -2**31 or res > 2**31 - 1:
        print(0)
    else:
        print(res)
solve()
