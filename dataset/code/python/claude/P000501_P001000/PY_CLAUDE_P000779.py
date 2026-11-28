
n=int(input());a=list(map(int,input().split()));q=int(input())
pre=[0]*(n+1)
for i in range(n): pre[i+1]=pre[i]+a[i]
for _ in range(q):
    l,r=map(int,input().split())
    print(pre[r+1]-pre[l])
