
n=int(input());a=list(map(int,input().split()))
from collections import Counter
cnt=Counter(a)
print(*sorted(k for k,v in cnt.items() if v==1))
