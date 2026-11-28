
n,m=int(input()),int(input())
res=[]
def bt(r,c,path):
    if r==n-1 and c==m-1: res.append(path);return
    for step in range(1,max(n,m)):
        if r+step<n: bt(r+step,c,path+f'D{step}')
        if c+step<m: bt(r,c+step,path+f'R{step}')
bt(0,0,'')
for p in res: print(p)
