

n=int(input());a=list(map(int,input().split()))
def msort(arr):
    if len(arr)<=1: return arr
    m=len(arr)//2
    return list(__import__('heapq').merge(msort(arr[:m]),msort(arr[m:])))
print(*msort(a))
