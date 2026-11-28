# problem title : Find Kth Missing Positive Number
# Count how many positive integers are missing before each array value.
n,k=map(int,input().split());a=list(map(int,input().split()));
for x in a:
 missing=x-(a.index(x)+1)
 if missing>=k: break
else: x=a[-1]+(k-(a[-1]-n))
if missing>=k: x-=missing-k
print(x)
