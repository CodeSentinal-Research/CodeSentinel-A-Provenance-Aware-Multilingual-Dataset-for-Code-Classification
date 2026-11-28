
n=int(input());h=list(map(int,input().split()))
stk=[];max_area=0;h.append(0)
for i,v in enumerate(h):
    while stk and h[stk[-1]]>v:
        height=h[stk.pop()]
        width=i if not stk else i-stk[-1]-1
        max_area=max(max_area,height*width)
    stk.append(i)
print(max_area)
