
n,t=map(int,input().split())
a=sorted(map(int,input().split()))
for i in range(n-2):
    lo,hi=i+1,n-1
    while lo<hi:
        s=a[i]+a[lo]+a[hi]
        if s==t: print('Yes');exit()
        elif s<t: lo+=1
        else: hi-=1
print('No')
