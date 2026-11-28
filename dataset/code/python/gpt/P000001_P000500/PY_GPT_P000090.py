# problem title : Calculate nCr
# Multiplicative combination avoids computing three separate factorials.
n, r = map(int, input().split())
r = min(r, n - r)
value = 1
for i in range(1, r + 1):
    value = value * (n - r + i) // i
print(value)
