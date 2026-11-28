# problem title : Find Missing Number
# XOR cancels every number appearing in both the range and the input.
n = int(input()); a = list(map(int, input().split()))[:n]
missing = n
for i, value in enumerate(a):
    missing ^= i ^ value
print(missing)
