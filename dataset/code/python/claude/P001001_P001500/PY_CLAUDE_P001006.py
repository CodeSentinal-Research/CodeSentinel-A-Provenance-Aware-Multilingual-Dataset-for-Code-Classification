
n=int(input());a=list(map(int,input().split()))
for i in range(n//2-1,-1,-1):
    l,r=2*i+1,2*i+2
    smallest=i
    if l<n and a[l]<a[smallest]: smallest=l
    if r<n and a[r]<a[smallest]: smallest=r
    if smallest!=i: print('false');exit()
print('true')
