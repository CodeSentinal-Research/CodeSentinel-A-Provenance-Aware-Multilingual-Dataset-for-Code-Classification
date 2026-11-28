# problem title : Linear Search
# Linear search returns the first zero-based matching index.
n,t=map(int,input().split());a=list(map(int,input().split()));print(next((i for i,x in enumerate(a) if x==t),-1))
