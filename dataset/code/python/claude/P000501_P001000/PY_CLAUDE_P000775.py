
n=int(input())
res=[]
def bt(i,cur,last):
    if i==n: res.append(cur);return
    bt(i+1,cur+'0',0)
    if last==0: bt(i+1,cur+'1',1)
bt(0,'',0)
for r in res: print(r)
