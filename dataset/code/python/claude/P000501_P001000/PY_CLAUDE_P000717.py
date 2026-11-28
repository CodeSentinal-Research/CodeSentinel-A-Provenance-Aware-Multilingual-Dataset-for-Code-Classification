
s=input().strip()
res=[]
def bt(start,cur):
    if start==len(s): res.append(cur[:]);return
    for end in range(start+1,len(s)+1):
        sub=s[start:end]
        if sub==sub[::-1]: cur.append(sub);bt(end,cur);cur.pop()
bt(0,[])
for r in res: print(*r)
