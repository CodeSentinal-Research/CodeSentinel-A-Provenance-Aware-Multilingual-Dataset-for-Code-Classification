# problem title : Find Roots of Quadratic Equation
# Compute the discriminant to determine the quadratic roots.
import cmath
a, b, c = map(float, input().split())
d = b * b - 4 * a * c
root = cmath.sqrt(d)
x1 = (-b + root) / (2 * a)
x2 = (-b - root) / (2 * a)
print(x1, x2)
