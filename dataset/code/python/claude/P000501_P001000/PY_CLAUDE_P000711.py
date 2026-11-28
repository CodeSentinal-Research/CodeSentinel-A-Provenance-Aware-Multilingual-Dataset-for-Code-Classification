
n=int(input());a=list(map(int,input().split()))
for i in range(1<<n):
    sub=[a[j] for j in range(n) if i>>j&1]
    print(*sub if sub else ['{}'])
