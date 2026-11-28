import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    m = int(d[0])
    nums1 = list(map(int, d[1:m+1]))
    n = int(d[m+1])
    nums2 = list(map(int, d[m+2:m+2+n]))
    merged = sorted(nums1 + nums2)
    total = m + n
    if total % 2 == 0:
        print((merged[total//2 - 1] + merged[total//2]) / 2)
    else:
        print(merged[total//2])
solve()
