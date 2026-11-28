
n=int(input())
lo,hi=1,n
while lo<=hi:
    mid=(lo+hi)//2
    if mid*mid==n: print('true');exit()
    elif mid*mid<n: lo=mid+1
    else: hi=mid-1
print('false')
