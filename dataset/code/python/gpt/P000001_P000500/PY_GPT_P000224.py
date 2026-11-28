# problem title : Job Sequencing Problem
# Schedule the most profitable jobs first, placing each job in the latest free slot before its deadline.
n=int(input()); jobs=[input().split() for _ in range(n)]; jobs=[(x[0],int(x[1]),int(x[2])) for x in jobs]; jobs.sort(key=lambda x:x[2],reverse=True); slots=[False]*(max(x[1] for x in jobs)+1); profit=count=0
for _,d,p in jobs:
    for t in range(min(d,len(slots)-1),0,-1):
        if not slots[t]: slots[t]=True; profit+=p; count+=1; break
print(profit,count)
