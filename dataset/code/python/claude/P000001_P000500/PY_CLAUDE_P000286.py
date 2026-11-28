
s=input()
letters=[c for c in s if c.isalpha()]
res=list(s);li=0;ri=len(letters)-1;i=0;j=len(s)-1
while i<j:
    while i<j and not s[i].isalpha(): i+=1
    while i<j and not s[j].isalpha(): j-=1
    if i<j:
        res[i],res[j]=res[j],res[i];i+=1;j-=1
print(''.join(res))
