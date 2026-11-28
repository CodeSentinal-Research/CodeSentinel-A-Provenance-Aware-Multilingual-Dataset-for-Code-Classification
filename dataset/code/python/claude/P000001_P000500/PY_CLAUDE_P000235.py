
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
res = []
for i in range(r):
    res += A[i] if i%2==0 else A[i][::-1]
print(*res)
