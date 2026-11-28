
n=int(input())
logs=[input().strip() for _ in range(n)]
res=[0]*n;stk=[];prev=0
for log in logs:
    fid,typ,t=log.split(':');fid=int(fid);t=int(t)
    if typ=='start':
        if stk: res[stk[-1]]+=t-prev
        stk.append(fid);prev=t
    else:
        res[stk.pop()]+=t-prev+1;prev=t+1
print(*res)
