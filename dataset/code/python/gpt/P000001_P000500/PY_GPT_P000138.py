# problem title : Merge Two Sorted Arrays
# Merge two sorted lists by always taking the smaller front value.
m, n = map(int, input().split()); left = list(map(int, input().split()))[:m]; right = list(map(int, input().split()))[:n]
i = j = 0; merged = []
while i < m and j < n:
    if left[i] <= right[j]: merged.append(left[i]); i += 1
    else: merged.append(right[j]); j += 1
merged.extend(left[i:]); merged.extend(right[j:])
print(*merged)
