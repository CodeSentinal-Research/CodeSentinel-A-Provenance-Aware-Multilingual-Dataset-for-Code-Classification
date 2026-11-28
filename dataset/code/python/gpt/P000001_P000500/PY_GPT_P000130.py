# problem title : Next Smaller Element
# Maintain a monotonic increasing stack to find next smaller values.
n = int(input()); a = list(map(int, input().split()))[:n]
ans = [-1] * n; pending = []
for i, x in enumerate(a):
    while pending and a[pending[-1]] > x:
        ans[pending.pop()] = x
    pending.append(i)
print(*ans)
