
n=int(input());nums1=list(map(int,input().split()))
m=int(input());nums2=list(map(int,input().split()))
stk=[];mp={}
for v in nums2:
    while stk and stk[-1]<v: mp[stk.pop()]=v
    stk.append(v)
print(*[mp.get(v,-1) for v in nums1])
