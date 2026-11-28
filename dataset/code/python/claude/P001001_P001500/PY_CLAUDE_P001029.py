
n=int(input());a=list(map(int,input().split()))

for i in range(n//2-1,-1,-1):
    j=i
    while True:
        largest=j;l=2*j+1;r=2*j+2
        if l<n and a[l]>a[largest]: largest=l
        if r<n and a[r]>a[largest]: largest=r
        if largest==j: break
        a[j],a[largest]=a[largest],a[j];j=largest
print(*a)
