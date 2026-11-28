
n=int(input());a=list(map(int,input().split()))

pre_min=[0]*n;pre_min[0]=a[0]
for i in range(1,n): pre_min[i]=min(pre_min[i-1],a[i])
print(pre_min[-1])
