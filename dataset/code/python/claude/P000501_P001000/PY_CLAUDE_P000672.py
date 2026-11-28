
n=int(input());a=list(map(int,input().split()));N=int(input())
res=[a[i] for i in range(n) if (i+1)%N!=0]
print(*res if res else [''])
