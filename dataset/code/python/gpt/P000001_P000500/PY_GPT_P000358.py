# problem title : Search Negative Number
# Scan left to right and stop at the first negative value.
n=int(input());a=list(map(int,input().split()));print(next((i for i,x in enumerate(a) if x<0),-1))
