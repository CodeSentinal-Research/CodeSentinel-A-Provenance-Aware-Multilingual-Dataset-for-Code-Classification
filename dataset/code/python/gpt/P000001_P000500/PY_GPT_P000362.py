# problem title : Search Value Greater Than Target
# Find the first element strictly greater than the target.
n=int(input());a=list(map(int,input().split()));x=int(input());print(next((i for i,v in enumerate(a) if v>x),-1))
