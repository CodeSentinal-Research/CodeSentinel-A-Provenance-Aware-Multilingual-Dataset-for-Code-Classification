# problem title : Search Odd Number
# The parity test identifies the first odd element.
n=int(input());a=list(map(int,input().split()));print(next((i for i,x in enumerate(a) if x%2),-1))
