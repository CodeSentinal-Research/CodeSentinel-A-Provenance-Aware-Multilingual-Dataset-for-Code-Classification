
n=int(input());a=[input().strip() for _ in range(n)]
best=0
def bt(i,cur):
    global best;best=max(best,len(cur))
    for j in range(i,n):
        if len(set(a[j]))==len(a[j]) and not set(cur)&set(a[j]):
            bt(j+1,cur+a[j])
bt(0,'');print(best)
