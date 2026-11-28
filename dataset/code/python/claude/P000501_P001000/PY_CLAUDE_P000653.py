

n=int(input());a=list(map(int,input().split()))
b=a[:]
for i in range(0,n-1,2): b[i],b[i+1]=b[i+1],b[i]
print(' '.join(map(str,b)))
