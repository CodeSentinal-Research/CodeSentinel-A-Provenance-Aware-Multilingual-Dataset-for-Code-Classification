# problem title : Find Missing Element in AP
# The common difference is recovered from the first and last values with one term missing.
n=int(input());a=list(map(int,input().split()));d=(a[-1]-a[0])//n
for i in range(len(a)-1):
 if a[i+1]-a[i]!=d:print(a[i]+d);break
else:print(a[-1]+d)
