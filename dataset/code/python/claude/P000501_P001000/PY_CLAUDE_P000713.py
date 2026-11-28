
n=int(input());a=list(map(int,input().split()));t=int(input())
res=[]
def bt(start,cur,rem):
    if rem==0: res.append(cur[:]);return
    for i in range(start,n):
        if a[i]<=rem: cur.append(a[i]);bt(i,cur,rem-a[i]);cur.pop()
bt(0,[],t)
for r in res: print(*r)
