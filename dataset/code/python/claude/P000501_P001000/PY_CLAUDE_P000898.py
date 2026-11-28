
from math import gcd
num,den=int(input()),int(input())
g=gcd(abs(num),abs(den))
print(num//g,den//g)
