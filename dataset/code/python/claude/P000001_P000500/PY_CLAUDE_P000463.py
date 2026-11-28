
sizes=list(map(int,input().split()))
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
i=j=k=0;res=[]
while i<len(a) and j<len(b) and k<len(c):
    if a[i]==b[j]==c[k]: res.append(a[i]);i+=1;j+=1;k+=1
    elif a[i]<=b[j] and a[i]<=c[k]: i+=1
    elif b[j]<=a[i] and b[j]<=c[k]: j+=1
    else: k+=1
print(*res)
