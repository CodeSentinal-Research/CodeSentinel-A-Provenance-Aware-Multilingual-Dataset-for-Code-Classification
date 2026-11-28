# problem title : Search Maximum Value
# max with key returns the first index when equal maxima occur.
n=int(input());a=list(map(int,input().split()));print(max(range(n),key=a.__getitem__))
