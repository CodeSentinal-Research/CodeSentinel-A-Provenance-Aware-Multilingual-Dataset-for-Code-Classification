# problem title : Check Whether Number is Perfect Square
# Binary search for an integer whose square equals n.
n = int(input())
lo, hi = 1, n
found = False
while lo <= hi:
    mid = (lo + hi) // 2
    sq = mid * mid
    if sq == n:
        found = True
        break
    if sq < n: lo = mid + 1
    else: hi = mid - 1
print("Perfect Square" if found else "Not Perfect Square")
