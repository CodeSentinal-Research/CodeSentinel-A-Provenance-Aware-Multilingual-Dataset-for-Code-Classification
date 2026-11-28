
s1,s2=input().split()
if abs(len(s1)-len(s2))>1: print('No');exit()
from collections import Counter
if len(s1)==len(s2):
    diff=sum((Counter(s1)-Counter(s2)).values())
    print('Yes' if diff<=1 else 'No')
else:
    shorter,longer=(s1,s2) if len(s1)<len(s2) else (s2,s1)
    for i in range(len(longer)):
        t=longer[:i]+longer[i+1:]
        if Counter(t)==Counter(shorter): print('Yes');exit()
    print('No')
