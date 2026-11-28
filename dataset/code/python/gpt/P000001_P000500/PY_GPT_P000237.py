# problem title : Rotate each Row of Matrix by K
# A row rotation is a cyclic slice; this rotates each row to the right by K.
r,c,k=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; k%=c
for row in a: row[:]=row[-k:]+row[:-k] if k else row
for row in a: print(*row)
