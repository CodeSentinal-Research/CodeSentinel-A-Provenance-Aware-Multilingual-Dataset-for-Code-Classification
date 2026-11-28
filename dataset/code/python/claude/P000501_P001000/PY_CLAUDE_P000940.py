
n=int(input());piles=list(map(int,input().split()))
xr=0
for p in piles: xr^=p

if all(p<=1 for p in piles): print('First' if sum(piles)%2==1 else 'Second')
else: print('First' if xr!=0 else 'Second')
