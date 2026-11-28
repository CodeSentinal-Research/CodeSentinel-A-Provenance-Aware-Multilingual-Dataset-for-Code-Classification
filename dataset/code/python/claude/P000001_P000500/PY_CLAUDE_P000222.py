
n = int(input())
arr = list(map(int, input().split()))
dep = list(map(int, input().split()))
arr.sort(); dep.sort()
plat=1;res=1;i=1;j=0
while i<n and j<n:
    if arr[i]<=dep[j]: plat+=1;i+=1
    else: plat-=1;j+=1
    res=max(res,plat)
print(res)
