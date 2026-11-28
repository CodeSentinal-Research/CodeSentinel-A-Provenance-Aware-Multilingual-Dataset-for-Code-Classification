
n=int(input());piles=list(map(int,input().split()))
xr=0
for p in piles: xr^=p
print('First' if xr!=0 else 'Second')
