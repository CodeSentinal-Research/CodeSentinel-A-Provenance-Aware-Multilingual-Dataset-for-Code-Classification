
n,m=map(int,input().split())
res=[]
def bt(r,c,path):
    if r==n-1 and c==m-1: res.append(path);return
    for dr,dc,d in [(0,1,'R'),(1,0,'D'),(1,1,'DG')]:
        nr,nc=r+dr,c+dc
        if 0<=nr<n and 0<=nc<m: bt(nr,nc,path+d)
bt(0,0,'')
for p in res: print(p)
