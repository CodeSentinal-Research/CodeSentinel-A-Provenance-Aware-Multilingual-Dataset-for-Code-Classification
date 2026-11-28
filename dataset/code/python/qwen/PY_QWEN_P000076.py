import cmath
a, b, c = map(float, input().split())
d = b ** 2 - 4 * a * c
r1 = (-b + cmath.sqrt(d)) / (2 * a)
r2 = (-b - cmath.sqrt(d)) / (2 * a)
if r1.imag == 0:
    r1 = r1.real
if r2.imag == 0:
    r2 = r2.real
print(r1, r2)
