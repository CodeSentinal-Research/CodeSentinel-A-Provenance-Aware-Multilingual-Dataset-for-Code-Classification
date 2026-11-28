
line1=input();line2=input()
s=line1.strip()
words=set(line2.strip().split())
n=len(s);dp=[False]*(n+1);dp[0]=True
for i in range(1,n+1):
    for j in range(i):
        if dp[j] and s[j:i] in words: dp[i]=True;break
print('Yes' if dp[n] else 'No')
