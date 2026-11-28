# problem title : Container With Most Water
# Two pointers choose the widest useful pair while moving the shorter wall.
n = int(input()); h = list(map(int, input().split()))[:n]
left, right, best = 0, n - 1, 0
while left < right:
    best = max(best, min(h[left], h[right]) * (right - left))
    if h[left] < h[right]: left += 1
    else: right -= 1
print(best)
