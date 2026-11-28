
n=int(input());a=list(map(int,input().split()));k=int(input())
res=[a[i] for i in range(n) if (i+1)%k!=0]
print(*res if res else [''])
