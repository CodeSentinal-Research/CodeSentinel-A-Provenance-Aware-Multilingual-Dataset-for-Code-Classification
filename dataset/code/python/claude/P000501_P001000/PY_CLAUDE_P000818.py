
n=int(input());a=list(map(int,input().split()));t=int(input())
lo,hi=0,n-1
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]==t: print('true');exit()
    if a[lo]==a[mid]==a[hi]: lo+=1;hi-=1
    elif a[lo]<=a[mid]:
        if a[lo]<=t<a[mid]: hi=mid-1
        else: lo=mid+1
    else:
        if a[mid]<t<=a[hi]: lo=mid+1
        else: hi=mid-1
print('false')
