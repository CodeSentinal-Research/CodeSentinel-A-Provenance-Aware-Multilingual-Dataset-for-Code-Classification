
n=int(input());petrol=list(map(int,input().split()));dist=list(map(int,input().split()))
start=0;fuel=0;deficit=0
for i in range(n):
    fuel+=petrol[i]-dist[i]
    if fuel<0: deficit+=fuel;fuel=0;start=i+1
print(start if fuel+deficit>=0 else -1)
