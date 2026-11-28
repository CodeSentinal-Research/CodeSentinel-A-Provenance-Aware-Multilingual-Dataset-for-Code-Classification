
n=int(input());a=list(map(int,input().split()))
count=[0]
def merge_sort(arr):
    if len(arr)<=1: return arr
    m=len(arr)//2;L=merge_sort(arr[:m]);R=merge_sort(arr[m:])
    res=[];i=j=0
    while i<len(L) and j<len(R):
        if L[i]<=R[j]: res.append(L[i]);i+=1
        else: count[0]+=len(L)-i;res.append(R[j]);j+=1
    return res+L[i:]+R[j:]
merge_sort(a);print(count[0])
