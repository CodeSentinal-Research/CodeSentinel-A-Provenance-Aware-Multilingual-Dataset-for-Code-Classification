
word=input().strip()
res=[]
def bt(i,cur,cnt):
    if i==len(word):
        res.append(cur+(str(cnt) if cnt else ''))
        return
    bt(i+1,cur,cnt+1)
    bt(i+1,cur+(str(cnt) if cnt else '')+word[i],0)
bt(0,'',0)
for r in sorted(res): print(r)
