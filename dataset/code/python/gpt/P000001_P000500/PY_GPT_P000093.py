# problem title : Find Sum of GP Series
# Add each term of the geometric progression; n is small by the constraints.
a, r, n = map(float, input().split())
total = 0.0
term = a
for _ in range(int(n)):
    total += term
    term *= r
print(total)
