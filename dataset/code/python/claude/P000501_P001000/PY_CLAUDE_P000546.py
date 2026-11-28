
n=int(input());s=input().strip();mn=int(input());mx=int(input())
reach=0;q=0;can=[False]*n;can[0]=True
for i in range(1,n):
    if i<=reach and s[i]=='0':
        can[i]=True;reach=max(reach,i+mx)
print('true' if can[n-1] else 'false')
