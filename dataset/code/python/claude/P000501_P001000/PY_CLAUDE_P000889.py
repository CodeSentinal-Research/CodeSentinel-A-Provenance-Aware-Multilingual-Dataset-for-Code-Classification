
n=int(input())
if n<2: print('false');exit()
from math import isqrt
print('true' if all(n%i!=0 for i in range(2,isqrt(n)+1)) else 'false')
