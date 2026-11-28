# problem title : Search Even Number
# The parity test identifies the first even element.
n=int(input());a=list(map(int,input().split()));print(next((i for i,x in enumerate(a) if x%2==0),-1))
