
s=input().strip()
best=0
for i in range(1,len(s)):
    score=s[:i].count('0')+s[i:].count('1')
    best=max(best,score)
print(best)
