# problem title : Print Matrix in Diagonal Order
# Traverse diagonals by increasing i+j and reverse every alternate diagonal.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; out=[]
for d in range(r+c-1):
    cur=[a[i][d-i] for i in range(r) if 0<=d-i<c]
    if d%2: cur.reverse()
    out+=cur
print(*out)
