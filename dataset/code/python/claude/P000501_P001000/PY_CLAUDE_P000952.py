
n=int(input());l,r=int(input()),int(input())
from math import gcd
print(sum(1 for x in range(l,r+1) if gcd(x,n)==1))
