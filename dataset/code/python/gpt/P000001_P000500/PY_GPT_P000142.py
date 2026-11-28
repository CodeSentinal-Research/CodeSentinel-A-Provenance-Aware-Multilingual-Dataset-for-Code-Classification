# problem title : Spiral Order Traversal of Matrix
# Shrink the four boundaries after consuming each matrix edge.
r, c = map(int, input().split()); m = [list(map(int, input().split()))[:c] for _ in range(r)]
top, bottom, left, right = 0, r - 1, 0, c - 1; out = []
while top <= bottom and left <= right:
    out.extend(m[top][left:right + 1]); top += 1
    for i in range(top, bottom + 1): out.append(m[i][right])
    right -= 1
    if top <= bottom:
        out.extend(reversed(m[bottom][left:right + 1])); bottom -= 1
    if left <= right:
        for i in range(bottom, top - 1, -1): out.append(m[i][left])
        left += 1
print(*out)
