# problem title : Search Value Less Than Target
# Find the first element strictly smaller than the target.
n=int(input());a=list(map(int,input().split()));x=int(input());print(next((i for i,v in enumerate(a) if v<x),-1))
