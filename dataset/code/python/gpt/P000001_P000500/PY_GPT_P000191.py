# problem title : Sort an Array of 0s 1s and 2s
# Count the three allowed values and rebuild the array in order.
n = int(input()); a = list(map(int, input().split()))[:n]
counts = [0, 0, 0]
for x in a: counts[x] += 1
print(*([0] * counts[0] + [1] * counts[1] + [2] * counts[2]))
