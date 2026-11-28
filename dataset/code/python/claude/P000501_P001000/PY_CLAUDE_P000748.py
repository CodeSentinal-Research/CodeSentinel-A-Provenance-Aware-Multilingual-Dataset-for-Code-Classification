
t=int(input())
res=[]
def bt(rem,path):
    if rem==0: res.append(path[:]);return
    for d in range(1,7):
        if d<=rem: path.append(d);bt(rem-d,path);path.pop()
bt(t,[])
for r in res: print(*r)
