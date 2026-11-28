
n=int(input());a=list(map(int,input().split()))
for i in range(n//2-1,-1,-1):
    l,r=2*i+1,2*i+2
    largest=i
    if l<n and a[l]>a[largest]: largest=l
    if r<n and a[r]>a[largest]: largest=r
    if largest!=i: print('false');exit()
print('true')
