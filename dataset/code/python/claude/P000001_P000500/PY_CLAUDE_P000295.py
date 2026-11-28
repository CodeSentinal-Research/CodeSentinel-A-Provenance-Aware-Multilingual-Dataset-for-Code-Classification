
s=input().strip()
i=0;n=len(s)
if i<n and s[i] in '+-': sign=1 if s[i]=='+' else -1;i+=1
else: sign=1
res=0
while i<n and s[i].isdigit(): res=res*10+int(s[i]);i+=1
res*=sign
res=max(-2**31,min(2**31-1,res))
print(res)
