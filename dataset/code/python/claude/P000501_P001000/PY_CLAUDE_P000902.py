
n=int(input());a=list(map(int,input().split()));q=int(input())
for _ in range(q):
    l,r,x=map(int,input().split())
    print(sum(1 for v in a[l-1:r] if v%x==0))
