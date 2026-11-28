
n=int(input())
if n>0 and (n&(n-1))==0: print(n.bit_length())
else: print(-1)
