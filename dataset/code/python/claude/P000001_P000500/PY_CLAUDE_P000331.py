
n=int(input())
m=int(input())
logs=[input().strip() for _ in range(m)]
res=[0]*n;stack=[];prev=0
for log in logs:
    fid,typ,time=log.split(':');fid=int(fid);time=int(time)
    if typ=='start':
        if stack: res[stack[-1]]+=time-prev
        stack.append(fid);prev=time
    else:
        res[stack.pop()]+=time-prev+1;prev=time+1
print(*res)
