# problem title : Count Even and Odd Elements
# Count parity classes independently.
n = int(input()); values = list(map(int, input().split()))[:n]
even = sum(x % 2 == 0 for x in values)
print(even, n - even)
