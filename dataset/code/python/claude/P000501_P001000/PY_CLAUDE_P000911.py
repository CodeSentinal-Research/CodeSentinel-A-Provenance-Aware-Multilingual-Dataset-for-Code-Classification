
rows=int(input())
tri=[[1]]
for i in range(1,rows):
    row=[1]+[tri[i-1][j]+tri[i-1][j+1] for j in range(i-1)]+[1]
    tri.append(row)
for row in tri: print(*row)
