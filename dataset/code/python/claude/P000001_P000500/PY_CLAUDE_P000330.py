
line1=input().strip();n=int(input())
s=line1
words=[input().strip() for _ in range(n)]
bold=[False]*len(s)
for w in words:
    i=s.find(w)
    while i!=-1:
        for k in range(i,i+len(w)): bold[k]=True
        i=s.find(w,i+1)
res='';i=0
while i<len(s):
    if bold[i] and (i==0 or not bold[i-1]): res+='<b>'
    res+=s[i]
    if bold[i] and (i==len(s)-1 or not bold[i+1]): res+='</b>'
    i+=1
print(res)
