
import sys
input = sys.stdin.readline
def merge_count(arr):
    if len(arr)<=1: return arr,0
    m=len(arr)//2
    l,cl=merge_count(arr[:m]); r,cr=merge_count(arr[m:])
    merged=[]; inv=cl+cr; i=j=0
    while i<len(l) and j<len(r):
        if l[i]<=r[j]: merged.append(l[i]);i+=1
        else: merged.append(r[j]);j+=1;inv+=len(l)-i
    merged+=l[i:]+r[j:]
    return merged,inv
n=int(input())
a=list(map(int,input().split()))
_,ans=merge_count(a)
print(ans)
