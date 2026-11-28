# problem title : Linear Search
# Linear search returns the first zero-based occurrence.
n, target = map(int, input().split()); a = list(map(int, input().split()))[:n]
answer = -1
for i, value in enumerate(a):
    if value == target:
        answer = i
        break
print(answer)
