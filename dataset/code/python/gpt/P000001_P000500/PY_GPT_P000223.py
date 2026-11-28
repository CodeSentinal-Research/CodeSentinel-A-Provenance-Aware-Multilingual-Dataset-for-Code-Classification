# problem title : Activity Selection Problem
# Select the activity with the earliest finishing time to leave maximum room for later activities.
n=int(input()); acts=[tuple(map(int,input().split())) for _ in range(n)]; acts.sort(key=lambda x:x[1]); end=-10**18; ans=0
for s,f in acts:
    if s>=end: ans+=1; end=f
print(ans)
