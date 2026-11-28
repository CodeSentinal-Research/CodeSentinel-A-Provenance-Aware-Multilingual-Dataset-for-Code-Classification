# problem title : Longest Decreasing Subarray
# A decreasing run is extended only when the next value is smaller.
n = int(input()); a = list(map(int, input().split()))[:n]
longest = current = 1
for x, y in zip(a, a[1:]):
    current = current + 1 if y < x else 1
    longest = max(longest, current)
print(longest)
