
s=input().strip()
res=[]
def bt(start,parts):
    if len(parts)==4 and start==len(s): res.append('.'.join(parts));return
    if len(parts)==4: return
    for l in range(1,4):
        if start+l>len(s): break
        part=s[start:start+l]
        if (part[0]=='0' and l>1) or int(part)>255: continue
        bt(start+l,parts+[part])
bt(0,[])
for r in res: print(r)
