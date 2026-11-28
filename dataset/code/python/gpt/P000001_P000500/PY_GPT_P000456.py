# problem title : Koko Eating Bananas
# Test an eating speed by counting the hours needed for all piles.
n,h=map(int,input().split());a=list(map(int,input().split()));lo,hi=1,max(a)
while lo<hi:
 m=(lo+hi)//2
 hours=sum((x+m-1)//m for x in a)
 if hours<=h:hi=m
 else:lo=m+1
print(lo)
