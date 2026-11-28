
rows,cols,x=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(rows)]
r,c=0,cols-1
while r<rows and c>=0:
    if mat[r][c]==x: print('Found');exit()
    elif mat[r][c]>x: c-=1
    else: r+=1
print('Not Found')
