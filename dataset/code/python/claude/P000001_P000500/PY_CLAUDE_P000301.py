
s = input()
res = []
def bt(start, parts):
    if len(parts)==4:
        if start==len(s): res.append('.'.join(parts))
        return
    for l in range(1,4):
        if start+l>len(s): break
        seg=s[start:start+l]
        if (seg[0]=='0' and l>1) or int(seg)>255: continue
        bt(start+l, parts+[seg])
bt(0,[])
print('\n'.join(res) if res else "")
