# problem title : Search Positive Number
# The first strictly positive value determines the required index.
n=int(input());a=list(map(int,input().split()));print(next((i for i,x in enumerate(a) if x>0),-1))
