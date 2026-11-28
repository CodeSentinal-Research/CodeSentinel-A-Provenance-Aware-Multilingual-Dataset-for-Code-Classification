# problem title : Check if Two Matrices are Identical
# Matrix identity requires equal dimensions and equal values at every position.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; b=[list(map(int,input().split())) for _ in range(r)]; print("Identical" if a==b else "Not Identical")
