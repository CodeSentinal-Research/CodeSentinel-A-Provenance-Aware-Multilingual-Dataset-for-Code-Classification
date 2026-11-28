# problem title : Count Inversions
# Merge sort counts cross inversions while merging two sorted halves.
def merge(a):
    if len(a)<2:return a,0
    m=len(a)//2; l,x=merge(a[:m]); r,y=merge(a[m:]); i=j=inv=0; out=[]
    while i<len(l) and j<len(r):
        if l[i]<=r[j]:out.append(l[i]);i+=1
        else:out.append(r[j]);inv+=len(l)-i;j+=1
    return out+l[i:]+r[j:],x+y+inv
n=int(input()); a=list(map(int,input().split())); print(merge(a)[1])
