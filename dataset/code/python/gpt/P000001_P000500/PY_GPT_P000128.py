# problem title : Trapping Rain Water
# Prefix maxima and suffix maxima determine water above each bar.
n = int(input()); h = list(map(int, input().split()))[:n]
left_max = [0] * n; right_max = [0] * n
for i in range(n): left_max[i] = max(left_max[i - 1] if i else 0, h[i])
for i in range(n - 1, -1, -1): right_max[i] = max(right_max[i + 1] if i + 1 < n else 0, h[i])
print(sum(min(left_max[i], right_max[i]) - h[i] for i in range(n)))
