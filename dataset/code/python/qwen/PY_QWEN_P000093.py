a, r, n = map(float, input().split())
n = int(n)
if r == 1:
    print(a * n)
else:
    print(a * (1 - r ** n) / (1 - r))
