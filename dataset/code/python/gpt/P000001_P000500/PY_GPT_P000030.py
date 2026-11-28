# problem title : LCM of Two Numbers
import math
a, b = map(int, input().split())
print(a * b // math.gcd(a, b))
