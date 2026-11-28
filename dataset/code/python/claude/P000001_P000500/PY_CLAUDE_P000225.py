
n = int(input())
a = list(map(int, input().split()))
b = sorted(range(n), key=lambda i: a[i])
vis = [False]*n
swaps = 0
for i in range(n):
    if vis[i] or b[i]==i: continue
    j=i; cycle=0
    while not vis[j]: vis[j]=True; j=b[j]; cycle+=1
    swaps+=cycle-1
print(swaps)
