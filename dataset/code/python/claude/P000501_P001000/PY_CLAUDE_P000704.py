
s=input().strip()
res=[]
for i in range(1<<len(s)):
    sub=''.join(s[j] for j in range(len(s)) if i>>j&1)
    if sub: res.append(sub)
for r in sorted(set(res)): print(r)
