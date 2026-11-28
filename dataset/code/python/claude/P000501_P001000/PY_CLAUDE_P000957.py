
a,b,x,y=int(input()),int(input()),int(input()),int(input())
from math import gcd
g=gcd(a,b)
print('true' if a*x+b*y==g else 'false')
