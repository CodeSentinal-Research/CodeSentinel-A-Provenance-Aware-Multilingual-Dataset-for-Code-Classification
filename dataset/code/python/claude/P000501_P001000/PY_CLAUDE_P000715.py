
k,t=int(input()),int(input())
res=[]
def bt(start,cur,rem):
    if len(cur)==k and rem==0: res.append(cur[:]);return
    if len(cur)==k or rem<=0: return
    for i in range(start,10):
        cur.append(i);bt(i+1,cur,rem-i);cur.pop()
bt(1,[],t)
for r in res: print(*r)
