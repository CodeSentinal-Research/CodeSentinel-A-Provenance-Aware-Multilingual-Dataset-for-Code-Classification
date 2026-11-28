
s=input().strip()
res=list(s)
for i in range(1,len(s),2):
    res[i]=chr(ord(s[i-1])+int(s[i]))
print(''.join(res))
