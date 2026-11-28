# problem title : Find Peak Element
# Check each position against its available neighbors and return any peak.
n = int(input()); a = list(map(int, input().split()))[:n]
peak = 0
for i, x in enumerate(a):
    left_ok = i == 0 or x > a[i - 1]
    right_ok = i == n - 1 or x > a[i + 1]
    if left_ok and right_ok:
        peak = i; break
print(peak)
