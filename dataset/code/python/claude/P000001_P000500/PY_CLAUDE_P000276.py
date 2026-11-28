
n=int(input());s='1'
for _ in range(n-1):
    ns='';i=0
    while i<len(s):
        cnt=1
        while i+cnt<len(s) and s[i+cnt]==s[i]: cnt+=1
        ns+=str(cnt)+s[i]; i+=cnt
    s=ns
print(s)
