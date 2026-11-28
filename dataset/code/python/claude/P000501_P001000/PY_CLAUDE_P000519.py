
n=int(input());h=list(map(int,input().split()))
stk=[];mx=0;h.append(0)
for i,v in enumerate(h):
    while stk and h[stk[-1]]>v:
        ht=h[stk.pop()]
        w=i if not stk else i-stk[-1]-1
        mx=max(mx,ht*w)
    stk.append(i)
print(mx)
