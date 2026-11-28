# problem title : Find Common Elements in Three Sorted Arrays
# Three pointers advance the smallest current value until all three match.
aN,bN,cN=map(int,input().split()); a=list(map(int,input().split())); b=list(map(int,input().split())); c=list(map(int,input().split())); i=j=k=0; out=[]
while i<aN and j<bN and k<cN:
    if a[i]==b[j]==c[k]: out.append(a[i]); i+=1;j+=1;k+=1
    elif min(a[i],b[j],c[k])==a[i]: i+=1
    elif min(a[i],b[j],c[k])==b[j]: j+=1
    else: k+=1
print(*out)
