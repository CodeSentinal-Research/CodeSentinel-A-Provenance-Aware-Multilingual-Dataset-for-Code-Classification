import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    l, r = 0, n - 1
    while l < r:
        mid = (l + r) // 2
        if mid % 2 == 1: mid -= 1
        if nums[mid] == nums[mid+1]:
            l = mid + 2
        else:
            r = mid
    print(nums[l])
solve()
