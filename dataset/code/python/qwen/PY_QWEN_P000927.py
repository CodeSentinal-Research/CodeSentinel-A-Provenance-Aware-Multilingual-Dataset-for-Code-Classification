import sys
def solve():
    d = sys.stdin.read().split()
    num_str, a, b = d[0], int(d[1]), int(d[2])
    val = int(num_str, a)
    if val == 0:
        print("0")
        return
    chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    res = []
    while val > 0:
        res.append(chars[val % b])
        val //= b
    print("".join(res[::-1]))
solve()
