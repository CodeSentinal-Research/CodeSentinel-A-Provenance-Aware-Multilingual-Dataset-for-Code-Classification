
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
import bisect
lo, hi = 1, 10**9
while lo < hi:
    mid = (lo+hi)//2
    cnt = sum(bisect.bisect_right(row, mid) for row in A)
    if cnt <= (r*c)//2: lo = mid+1
    else: hi = mid
print(lo)
