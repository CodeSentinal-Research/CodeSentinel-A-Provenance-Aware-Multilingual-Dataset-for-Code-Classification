
n=int(input());candies=list(map(int,input().split()));k=int(input())
def ok(c):
    if c==0: return True
    return sum(v//c for v in candies)>=k
lo,hi=0,max(candies)
while lo<hi:
    mid=(lo+hi+1)//2
    if ok(mid): lo=mid
    else: hi=mid-1
print(lo)
