
n=int(input());a=list(map(int,input().split()))

def sift_down(arr,sz,root):
    while True:
        largest=root;l=2*root+1;r=2*root+2
        if l<sz and arr[l]>arr[largest]: largest=l
        if r<sz and arr[r]>arr[largest]: largest=r
        if largest==root: break
        arr[root],arr[largest]=arr[largest],arr[root];root=largest
for i in range(n//2-1,-1,-1): sift_down(a,n,i)
print(*a)
