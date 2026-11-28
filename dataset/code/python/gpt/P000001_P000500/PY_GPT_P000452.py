# problem title : Find Element Appearing Once
# XOR cancels every paired value and leaves the element appearing once.
n=int(input());a=list(map(int,input().split()));x=0
for v in a:x^=v
print(x)
