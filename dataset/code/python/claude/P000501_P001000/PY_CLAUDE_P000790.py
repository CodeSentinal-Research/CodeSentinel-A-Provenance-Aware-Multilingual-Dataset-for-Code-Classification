
n=int(input());a=list(map(int,input().split()));k=int(input())
seen={0:-1};s=0
for i,v in enumerate(a):
    s=(s+v)%k
    if s in seen:
        if i-seen[s]>=2: print('true');exit()
    else: seen[s]=i
print('false')
