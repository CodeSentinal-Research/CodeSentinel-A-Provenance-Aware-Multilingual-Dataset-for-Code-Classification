
n=int(input());enc=list(map(int,input().split()))

total=0
for i in range(1,n+1): total^=i

xor_odd=0
for i in range(1,n-1,2): xor_odd^=enc[i]
first=total^xor_odd
res=[first]
for v in enc: res.append(res[-1]^v)
print(*res)
