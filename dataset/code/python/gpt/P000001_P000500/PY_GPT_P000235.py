# problem title : Print Matrix in Zigzag Order
# Alternate left-to-right and right-to-left traversal for each row.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; out=[]
for i,row in enumerate(a): out += row if i%2==0 else row[::-1]
print(*out)
