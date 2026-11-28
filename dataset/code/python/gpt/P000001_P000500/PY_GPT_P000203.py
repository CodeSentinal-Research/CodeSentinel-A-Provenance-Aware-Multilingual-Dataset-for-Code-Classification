# problem title : Find the Maximum Repeating Number
# Count frequencies and choose the largest value whose frequency reaches K.
n,k=map(int,input().split()); a=list(map(int,input().split()))
f={}
for x in a:f[x]=f.get(x,0)+1
v=[x for x,c in f.items() if c>=k]
print(max(v) if v else -1)
