
x,n=int(input()),int(input())
ok=True
for _ in range(n):
    r,mod=map(int,input().split())
    if x%mod!=r: ok=False
print('true' if ok else 'false')
