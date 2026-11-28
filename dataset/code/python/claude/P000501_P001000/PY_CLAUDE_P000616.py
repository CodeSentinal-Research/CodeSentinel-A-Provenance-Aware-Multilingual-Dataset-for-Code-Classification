
n=int(input());a=list(map(int,input().split()))
for i in range(1,n,2):
    if i+1<n and (i//2+1)%2==0: pass
even=[a[i] for i in range(1,n,2)]
even=even[::-1]
j=0
for i in range(1,n,2): a[i]=even[j];j+=1
print(*a)
