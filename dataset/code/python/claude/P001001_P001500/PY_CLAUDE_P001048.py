
n=int(input());a=list(map(int,input().split()));i=int(input())
def heapify(arr,sz,root):
    largest=root;l=2*root+1;r=2*root+2
    if l<sz and arr[l]>arr[largest]: largest=l
    if r<sz and arr[r]>arr[largest]: largest=r
    if largest!=root: arr[root],arr[largest]=arr[largest],arr[root];heapify(arr,sz,largest)
heapify(a,n,i)
print(*a)
