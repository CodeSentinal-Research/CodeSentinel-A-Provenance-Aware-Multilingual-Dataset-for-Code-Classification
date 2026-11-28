# problem title : Find Sum of AP Series
# Sum of an arithmetic progression uses n/2 times first plus last term.
a, d, n = map(float, input().split())
last = a + (n - 1) * d
print(n * (a + last) / 2)
