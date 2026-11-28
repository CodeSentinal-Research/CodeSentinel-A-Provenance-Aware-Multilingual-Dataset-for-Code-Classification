
n=int(input());a=list(map(int,input().split()));q=int(input())
pre=[0]*(n+1)
for i in range(n): pre[i+1]=pre[i]+(1 if a[i]%2!=0 else 0)
for _ in range(q):
    l,r=map(int,input().split())
    print(pre[r+1]-pre[l])
