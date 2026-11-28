
a,b,n=int(input()),int(input()),int(input())
from math import gcd
mcn=a*b//gcd(a,b)-a-b
print('true' if n>mcn else 'false')
