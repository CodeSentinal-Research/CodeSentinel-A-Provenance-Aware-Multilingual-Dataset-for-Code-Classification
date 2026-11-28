def reverse(x: int) -> int:
    res = 0
    sign = [1,-1][x < 0]
    x *= sign
    while x:
        res = res*10 + x % 10
        x = x // 10
    res *= sign
    return res if -(2**31) <= res <= 2**31 - 1 else 0