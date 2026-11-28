
s=input().strip()
from collections import defaultdict
def parse(s,i):
    counts=defaultdict(int)
    while i<len(s) and s[i]!=')':
        if s[i]=='(':
            sub,i=parse(s,i+1);i+=1
            num=''
            while i<len(s) and s[i].isdigit(): num+=s[i];i+=1
            for k,v in sub.items(): counts[k]+=v*int(num or 1)
        elif s[i].isupper():
            j=i+1
            while j<len(s) and s[j].islower(): j+=1
            el=s[i:j];i=j
            num=''
            while i<len(s) and s[i].isdigit(): num+=s[i];i+=1
            counts[el]+=int(num or 1)
        else: i+=1
    return counts,i
counts,_=parse(s,0)
print(''.join(f'{k}{v if v>1 else ''}' for k,v in sorted(counts.items())))
