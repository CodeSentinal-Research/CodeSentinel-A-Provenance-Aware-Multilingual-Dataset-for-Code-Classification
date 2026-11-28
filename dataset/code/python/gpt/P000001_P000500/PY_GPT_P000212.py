# problem title : Can Place Flowers
# Greedily plant whenever both neighboring positions are empty.
n,k=map(int,input().split()); a=list(map(int,input().split())); placed=0
for i in range(n):
    if a[i]==0 and (i==0 or a[i-1]==0) and (i==n-1 or a[i+1]==0): a[i]=1; placed+=1
print("Yes" if placed>=k else "No")
