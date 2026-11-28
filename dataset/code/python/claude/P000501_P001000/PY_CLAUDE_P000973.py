
s=int(input())

if s<2 or s>12: print('0/36');exit()
cnt=sum(1 for i in range(1,7) for j in range(1,7) if i+j==s)
from math import gcd;g=gcd(cnt,36)
print(f'{cnt//g}/{36//g}')
