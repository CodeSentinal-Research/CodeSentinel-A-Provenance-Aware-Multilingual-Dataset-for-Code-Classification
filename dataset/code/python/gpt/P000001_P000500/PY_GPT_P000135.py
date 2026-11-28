# problem title : Sort Colors (Dutch National Flag)
# Dutch National Flag uses three regions for 0, 1 and 2.
n = int(input()); a = list(map(int, input().split()))[:n]
lo = mid = 0; hi = n - 1
while mid <= hi:
    if a[mid] == 0:
        a[lo], a[mid] = a[mid], a[lo]; lo += 1; mid += 1
    elif a[mid] == 1:
        mid += 1
    else:
        a[mid], a[hi] = a[hi], a[mid]; hi -= 1
print(*a)
