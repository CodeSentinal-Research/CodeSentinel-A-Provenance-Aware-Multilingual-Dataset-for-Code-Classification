# problem title : Search Minimum Value
# min with key returns the first index when equal minima occur.
n=int(input());a=list(map(int,input().split()));print(min(range(n),key=a.__getitem__))
