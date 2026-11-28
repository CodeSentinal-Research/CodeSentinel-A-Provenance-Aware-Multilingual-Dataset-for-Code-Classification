import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    xor_all = 0
    for i in range(n + 1):
        xor_all ^= i
    for x in nums:
        xor_all ^= x
    print(xor_all)
solve()
