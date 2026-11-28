import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    ans = 0
    for i in range(32):
        count_ones = sum((x >> i) & 1 for x in nums)
        ans += count_ones * (n - count_ones)
    print(ans)
solve()
