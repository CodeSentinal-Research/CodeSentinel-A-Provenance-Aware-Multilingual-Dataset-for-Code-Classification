# problem title : Degree of an Array
# Store frequency, first index, and last index; the degree determines the required range.
n=int(input()); a=list(map(int,input().split())); freq={}; first={}; last={}
for i,x in enumerate(a): freq[x]=freq.get(x,0)+1; first.setdefault(x,i); last[x]=i
d=max(freq.values()); print(min(last[x]-first[x]+1 for x in freq if freq[x]==d))
