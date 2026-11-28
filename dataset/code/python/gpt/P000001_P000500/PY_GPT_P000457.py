# problem title : Find Smallest Divisor
# A divisor is feasible when the rounded-up quotient sum is within the threshold.
n,t=map(int,input().split());a=list(map(int,input().split()));lo,hi=1,max(a)
while lo<hi:
 d=(lo+hi)//2
 if sum((x+d-1)//d for x in a)<=t:hi=d
 else:lo=d+1
print(lo)
