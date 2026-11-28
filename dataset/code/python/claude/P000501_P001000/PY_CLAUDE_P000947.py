
M,T=int(input()),int(input())
if T==0: print('true');exit()
if M*(M+1)//2<T: print('false');exit()
from functools import lru_cache
@lru_cache(None)
def dp(used,rem):
    for i in range(1,M+1):
        if not(used>>i&1) and (rem<=i or not dp(used|(1<<i),rem-i)): return True
    return False
print('true' if dp(0,T) else 'false')
