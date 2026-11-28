# problem title : Next Greater Element
# A decreasing monotonic stack gives the next greater value for each index.
n = int(input()); a = list(map(int, input().split()))[:n]
ans = [-1] * n; stack = []
for i, x in enumerate(a):
    while stack and a[stack[-1]] < x:
        ans[stack.pop()] = x
    stack.append(i)
print(*ans)
