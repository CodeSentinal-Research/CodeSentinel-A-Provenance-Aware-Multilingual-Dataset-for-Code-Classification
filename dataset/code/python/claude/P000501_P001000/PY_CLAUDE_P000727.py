
s=input().strip();m=int(input());dic=set(input().strip() for _ in range(m))

res=[]
def bt(start, path):
    if start==len(s): res.append(' '.join(path));return
    for end in range(start+1,len(s)+1):
        if s[start:end] in dic: bt(end, path+[s[start:end]])
bt(0,[])
for r in res: print(r)
