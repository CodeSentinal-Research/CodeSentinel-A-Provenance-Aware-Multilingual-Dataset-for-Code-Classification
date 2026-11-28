import math
a, b, c = map(int, input().split())
lcm_ab = a * b // math.gcd(a, b)
print(lcm_ab * c // math.gcd(lcm_ab, c))
