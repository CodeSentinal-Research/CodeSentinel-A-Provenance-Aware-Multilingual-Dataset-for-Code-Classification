import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    dividend, divisor = int(d[0]), int(d[1])
    sign = -1 if (dividend < 0) ^ (divisor < 0) else 1
    dvd, dvs = abs(dividend), abs(divisor)
    res = 0
    while dvd >= dvs:
        temp = dvs
        multiple = 1
        while dvd >= (temp << 1):
            temp <<= 1
            multiple <<= 1
        dvd -= temp
        res += multiple
    res *= sign
    res = max(-2**31, min(2**31 - 1, res))
    print(res)
solve()
