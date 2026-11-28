# problem title : Find Common Elements in Three Sorted Arrays
# Three pointers advance the smallest value until all three arrays agree.
aN,bN,cN=map(int,input().split());a=list(map(int,input().split()));b=list(map(int,input().split()));c=list(map(int,input().split()));i=j=k=0;o=[]
while i<aN and j<bN and k<cN:
 if a[i]==b[j]==c[k]:o.append(a[i]);i+=1;j+=1;k+=1
 else:
  m=min(a[i],b[j],c[k]);i+=a[i]==m;j+=b[j]==m;k+=c[k]==m
print(*o)
