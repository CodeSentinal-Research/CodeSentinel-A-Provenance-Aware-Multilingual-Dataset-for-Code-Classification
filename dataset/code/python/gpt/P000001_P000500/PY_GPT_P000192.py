# problem title : Move All Negative Elements to One Side
# Stable partition keeps all negative values on the left.
n = int(input()); a = list(map(int, input().split()))[:n]
result = [x for x in a if x < 0] + [x for x in a if x >= 0]
print(*result)
