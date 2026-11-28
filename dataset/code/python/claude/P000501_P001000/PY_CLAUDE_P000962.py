
a,b=int(input()),int(input())
from math import gcd
print(a*b//gcd(a,b)-a-b)
