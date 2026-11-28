# problem title : Find First Occurrence of an Element
# enumerate gives the first matching zero-based index directly.
n=int(input());a=list(map(int,input().split()));x=int(input());print(next((i for i,v in enumerate(a) if v==x),-1))
