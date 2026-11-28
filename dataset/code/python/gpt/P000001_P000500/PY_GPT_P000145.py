# problem title : Search a 2D Matrix
# The matrix is globally sorted, so binary-search its flattened index space.
r, c, target = map(int, input().split()); m = [list(map(int, input().split()))[:c] for _ in range(r)]
lo, hi = 0, r * c - 1; found = False
while lo <= hi:
    mid = (lo + hi) // 2
    value = m[mid // c][mid % c]
    if value == target: found = True; break
    if value < target: lo = mid + 1
    else: hi = mid - 1
print("Found" if found else "Not Found")
