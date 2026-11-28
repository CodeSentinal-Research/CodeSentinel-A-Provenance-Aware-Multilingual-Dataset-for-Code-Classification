
n=int(input());a=sorted(map(int,input().split()))

ans=min(a[-1]-a[2],a[-2]-a[1],a[-3]-a[0])
print(max(0,ans))
