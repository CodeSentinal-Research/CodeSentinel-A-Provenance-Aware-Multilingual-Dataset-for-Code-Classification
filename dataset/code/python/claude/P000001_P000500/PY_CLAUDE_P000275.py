
s=input();res='';i=0
while i<len(s):
    cnt=1
    while i+cnt<len(s) and s[i+cnt]==s[i]: cnt+=1
    res+=s[i]+(str(cnt) if cnt>1 else '')
    i+=cnt
print(res)
