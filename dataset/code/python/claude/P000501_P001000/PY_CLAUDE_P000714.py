
n=int(input());a=sorted(map(int,input().split()));t=int(input())
res=[]
def bt(start,cur,rem):
    if rem==0: res.append(tuple(cur));return
    for i in range(start,n):
        if i>start and a[i]==a[i-1]: continue
        if a[i]>rem: break
        cur.append(a[i]);bt(i+1,cur,rem-a[i]);cur.pop()
bt(0,[],t)
for r in sorted(set(res)): print(*r)
