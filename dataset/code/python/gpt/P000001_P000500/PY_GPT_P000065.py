# problem title : Find LCM of Three Numbers
# Combine three numbers using pairwise LCM.
from math import gcd
a, b, c = map(int, input().split())
def lcm(x, y):
    return x // gcd(x, y) * y
print(lcm(lcm(a, b), c))
