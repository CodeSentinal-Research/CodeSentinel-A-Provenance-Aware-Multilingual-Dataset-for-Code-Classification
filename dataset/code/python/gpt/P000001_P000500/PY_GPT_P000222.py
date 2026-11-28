# problem title : Minimum Number of Platforms Required
# Sorting arrivals and departures lets us sweep events and track simultaneous trains.
n=int(input()); arr=list(map(int,input().split())); dep=list(map(int,input().split())); arr.sort(); dep.sort(); i=j=cur=best=0
while i<n and j<n:
    if arr[i]<=dep[j]: cur+=1; best=max(best,cur); i+=1
    else: cur-=1; j+=1
print(best)
