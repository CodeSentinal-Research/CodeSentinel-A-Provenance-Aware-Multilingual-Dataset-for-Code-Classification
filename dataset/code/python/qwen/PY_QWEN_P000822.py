import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    k, x = int(d[n+1]), int(d[n+2])
    l, r = 0, n - k
    while l < r:
        mid = (l + r) // 2
        if x - nums[mid] > nums[mid+k] - x:
            l = mid + 1
        else:
            r = mid
    print(" ".join(map(str, nums[l:l+k])))
solve()
