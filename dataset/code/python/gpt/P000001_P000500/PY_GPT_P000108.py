# problem title : Check if Array is Sorted Descending
# Descending order requires each value to be at least the next one.
n = int(input()); a = list(map(int, input().split()))[:n]
valid = all(a[j] >= a[j + 1] for j in range(n - 1))
print("Sorted" if valid else "Not Sorted")
