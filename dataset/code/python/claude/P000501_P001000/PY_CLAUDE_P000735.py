
n=int(input());chars=input().split();k=int(input())
from itertools import product
for combo in product(chars,repeat=k): print(''.join(combo))
