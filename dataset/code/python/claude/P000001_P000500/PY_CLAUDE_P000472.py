
rows,cols=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(rows)]

for i in range(rows):
    for j in range(cols):
        v=mat[i][j]
        up=mat[i-1][j] if i>0 else -1
        dn=mat[i+1][j] if i<rows-1 else -1
        lt=mat[i][j-1] if j>0 else -1
        rt=mat[i][j+1] if j<cols-1 else -1
        if v>up and v>dn and v>lt and v>rt:
            print(v);exit()
