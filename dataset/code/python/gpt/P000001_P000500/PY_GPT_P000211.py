# problem title : Maximum Product of Three Numbers
# The best product is either the three largest values or two smallest negatives times the largest.
n=int(input()); a=list(map(int,input().split())); a.sort(); print(max(a[-1]*a[-2]*a[-3],a[0]*a[1]*a[-1]))
