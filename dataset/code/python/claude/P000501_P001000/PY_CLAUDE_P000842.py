
n=int(input());idx=int(input());maxSum=int(input())
def calc(peak,count):
    if peak>count: return (peak+(peak-count+1))*count//2
    return peak*(peak+1)//2+(count-peak)
def ok(val):
    left=calc(val,idx+1)
    right=calc(val,n-idx)
    return left+right-val<=maxSum
lo,hi=1,maxSum
while lo<hi:
    mid=(lo+hi+1)//2
    if ok(mid): lo=mid
    else: hi=mid-1
print(lo)
