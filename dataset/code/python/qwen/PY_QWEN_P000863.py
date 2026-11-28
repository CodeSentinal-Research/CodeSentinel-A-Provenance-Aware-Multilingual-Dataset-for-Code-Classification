import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    xor_all = 0
    for x in nums:
        xor_all ^= x
    rightmost_set_bit = xor_all & -xor_all
    num1, num2 = 0, 0
    for x in nums:
        if x & rightmost_set_bit:
            num1 ^= x
        else:
            num2 ^= x
    print(min(num1, num2), max(num1, num2))
solve()
