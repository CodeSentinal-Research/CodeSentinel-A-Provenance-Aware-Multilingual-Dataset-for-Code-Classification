
s=input().strip()
from collections import Counter
cnt=Counter(s);seen=set();stk=[]
for c in s:
    cnt[c]-=1
    if c in seen: continue
    while stk and stk[-1]>c and cnt[stk[-1]]>0: seen.discard(stk.pop())
    stk.append(c);seen.add(c)
print(''.join(stk))
